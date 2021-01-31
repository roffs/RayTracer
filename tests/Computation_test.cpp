#include <gtest/gtest.h>
#include <cmath>

#include "Computation.h"

#include "Tuple.h"
#include "Ray.h"
#include "Plane.h"
#include "Transformations.h"

TEST(Computation_test, precomputing_the_state_of_an_intersection) {
    Tuple rayOrigin = Tuple::Point(0.0f, 0.0f, -5.0f);
    Tuple rayDirection = Tuple::Vector(0.0f, 0.0f, 1.0f);
    Ray ray(rayOrigin, rayDirection);

    Sphere sphere = Sphere(); 
    Intersection i(sphere, 4.0f);

    Computation comp = prepareComputation(i, ray);

    Tuple expectedPoint = Tuple::Point(0.0f, 0.0f, -1.0f);
    Tuple expectedEyeDirection = Tuple::Vector(0.0f, 0.0f, -1.0f);
    Tuple expectedNormal = Tuple::Vector(0.0f, 0.0f, -1.0f);

    ASSERT_EQ(comp.t, i.t);
    ASSERT_TRUE(comp.object == i.object);
    ASSERT_TRUE(comp.point == expectedPoint);
    ASSERT_TRUE(comp.eyeDirection == expectedEyeDirection);
    ASSERT_TRUE(comp.normal == expectedNormal);
}

TEST(Computation_test, precomuptes_intersection_when_it_is_outside) {
    Tuple rayOrigin = Tuple::Point(0.0f, 0.0f, -5.0f);
    Tuple rayDirection = Tuple::Vector(0.0f, 0.0f, 1.0f);
    Ray ray(rayOrigin, rayDirection);

    Sphere sphere = Sphere(); 
    Intersection i(sphere, 4.0f);

    Computation comp = prepareComputation(i, ray);

    ASSERT_FALSE(comp.inside);
}

TEST(Computation_test, precomuptes_intersection_when_it_is_inside) {
    Tuple rayOrigin = Tuple::Point(0.0f, 0.0f, 0.0f);
    Tuple rayDirection = Tuple::Vector(0.0f, 0.0f, 1.0f);
    Ray ray(rayOrigin, rayDirection);

    Sphere sphere = Sphere(); 
    Intersection i(sphere, 1.0f);

    Computation comp = prepareComputation(i, ray);   

    Tuple expectedPoint = Tuple::Point(0.0f, 0.0f, 1.0f);
    Tuple expectedEyeDirection = Tuple::Vector(0.0f, 0.0f, -1.0f);
    Tuple expectedNormal = Tuple::Vector(0.0f, 0.0f, -1.0f);

    ASSERT_TRUE(comp.inside);
    ASSERT_TRUE(comp.point == expectedPoint);
    ASSERT_TRUE(comp.eyeDirection == expectedEyeDirection);
    ASSERT_TRUE(comp.normal == expectedNormal);
}

TEST(Computation_test, precomupte_should_offset_the_hitted_point) {
    Tuple rayOrigin = Tuple::Point(0.0f, 0.0f, -5.0f);
    Tuple rayDirection = Tuple::Vector(0.0f, 0.0f, 1.0f);
    Ray ray(rayOrigin, rayDirection);

    Sphere sphere;
    sphere.setTransformation(translation(0.0f, 0.0f, 1.0f));
    Intersection i(sphere, 5.0f);

    Computation comp = prepareComputation(i, ray);   

    ASSERT_TRUE(comp.overPoint.z < -EPSILON/2.0f);
    ASSERT_TRUE(comp.point.z > comp.overPoint.z);
}


TEST(Computation_test, precomputing_the_state_of_an_intersection_with_a_plane) {
    Tuple rayOrigin = Tuple::Point(0.0f, 0.0f, -5.0f);
    Tuple rayDirection = Tuple::Vector(0.0f, 0.0f, 1.0f);
    Ray ray(rayOrigin, rayDirection);

    Plane plane;
    Intersection i(plane, 4.0f);

    Computation comp = prepareComputation(i, ray);

    Tuple expectedPoint = Tuple::Point(0.0f, 0.0f, -1.0f);
    Tuple expectedEyeDirection = Tuple::Vector(0.0f, 0.0f, -1.0f);
    Tuple expectedNormal = Tuple::Vector(0.0f, 1.0f, 0.0f);

    ASSERT_EQ(comp.t, i.t);
    ASSERT_TRUE(comp.object == i.object);
    ASSERT_TRUE(comp.point == expectedPoint);
    ASSERT_TRUE(comp.eyeDirection == expectedEyeDirection);
    ASSERT_TRUE(comp.normal == expectedNormal);
}


TEST(Intersection_test, precomputes_the_reflection_vector) {
    Plane plane; 
    
    Tuple rayOrigin = Tuple::Point(0.0f, 1.0f, -1.0f);
    Tuple rayDirection = Tuple::Vector(0.0f, -sqrt(2.0f)/2.0f, sqrt(2.0f)/2.0f);
    Ray ray(rayOrigin, rayDirection);

    Intersection i(plane, sqrt(2.0f));

    Computation comp = prepareComputation(i, ray);
    ASSERT_TRUE(comp.reflectv == Tuple::Vector(0.0f, sqrt(2.0f)/2.0f, sqrt(2.0f)/2.0f));
}