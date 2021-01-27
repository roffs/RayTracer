#include <gtest/gtest.h>

#include "Computation.h"

#include "Tuple.h"
#include "Ray.h"

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