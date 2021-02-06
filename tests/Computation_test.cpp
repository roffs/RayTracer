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
    std::vector<Intersection> intersections = {i};
    Computation comp = prepareComputation(i, ray, intersections);

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
    std::vector<Intersection> intersections = {i};
    Computation comp = prepareComputation(i, ray, intersections);

    ASSERT_FALSE(comp.inside);
}

TEST(Computation_test, precomuptes_intersection_when_it_is_inside) {
    Tuple rayOrigin = Tuple::Point(0.0f, 0.0f, 0.0f);
    Tuple rayDirection = Tuple::Vector(0.0f, 0.0f, 1.0f);
    Ray ray(rayOrigin, rayDirection);

    Sphere sphere = Sphere(); 
    Intersection i(sphere, 1.0f);
    std::vector<Intersection> intersections = {i};
    Computation comp = prepareComputation(i, ray, intersections);

    Tuple expectedPoint = Tuple::Point(0.0f, 0.0f, 1.0f);
    Tuple expectedEyeDirection = Tuple::Vector(0.0f, 0.0f, -1.0f);
    Tuple expectedNormal = Tuple::Vector(0.0f, 0.0f, -1.0f);

    ASSERT_TRUE(comp.inside);
    ASSERT_TRUE(comp.point == expectedPoint);
    ASSERT_TRUE(comp.eyeDirection == expectedEyeDirection);
    ASSERT_TRUE(comp.normal == expectedNormal);
}

TEST(Computation_test, overPoint_should_offset_the_hitted_point) {
    Tuple rayOrigin = Tuple::Point(0.0f, 0.0f, -5.0f);
    Tuple rayDirection = Tuple::Vector(0.0f, 0.0f, 1.0f);
    Ray ray(rayOrigin, rayDirection);

    Sphere sphere;
    sphere.setTransformation(translation(0.0f, 0.0f, 1.0f));
    Intersection i(sphere, 5.0f);
    std::vector<Intersection> intersections = {i};
    Computation comp = prepareComputation(i, ray, intersections);  

    ASSERT_TRUE(comp.overPoint.z < -EPSILON/2.0f);
    ASSERT_TRUE(comp.point.z > comp.overPoint.z);
}

TEST(Computation_test, underPoint_should_offset_the_hitted_point) {
    Tuple rayOrigin = Tuple::Point(0.0f, 0.0f, -5.0f);
    Tuple rayDirection = Tuple::Vector(0.0f, 0.0f, 1.0f);
    Ray ray(rayOrigin, rayDirection);

    Sphere sphere;
    sphere.setTransformation(translation(0.0f, 0.0f, 1.0f));
    Intersection i(sphere, 5.0f);
    std::vector<Intersection> intersections = {i};
    Computation comp = prepareComputation(i, ray, intersections);  

    ASSERT_TRUE(comp.underPoint.z > EPSILON/2.0f);
    ASSERT_TRUE(comp.point.z < comp.underPoint.z);
}

TEST(Computation_test, precomputing_the_state_of_an_intersection_with_a_plane) {
    Tuple rayOrigin = Tuple::Point(0.0f, 0.0f, -5.0f);
    Tuple rayDirection = Tuple::Vector(0.0f, 0.0f, 1.0f);
    Ray ray(rayOrigin, rayDirection);

    Plane plane;
    Intersection i(plane, 4.0f);
    std::vector<Intersection> intersections = {i};
    Computation comp = prepareComputation(i, ray, intersections);

    Tuple expectedPoint = Tuple::Point(0.0f, 0.0f, -1.0f);
    Tuple expectedEyeDirection = Tuple::Vector(0.0f, 0.0f, -1.0f);
    Tuple expectedNormal = Tuple::Vector(0.0f, 1.0f, 0.0f);

    ASSERT_EQ(comp.t, i.t);
    ASSERT_TRUE(comp.object == i.object);
    ASSERT_TRUE(comp.point == expectedPoint);
    ASSERT_TRUE(comp.eyeDirection == expectedEyeDirection);
    ASSERT_TRUE(comp.normal == expectedNormal);
}


TEST(Computation_test, precomputes_the_reflection_vector) {
    Plane plane; 
    
    Tuple rayOrigin = Tuple::Point(0.0f, 1.0f, -1.0f);
    Tuple rayDirection = Tuple::Vector(0.0f, -sqrt(2.0f)/2.0f, sqrt(2.0f)/2.0f);
    Ray ray(rayOrigin, rayDirection);

    Intersection i(plane, sqrt(2.0f));
    std::vector<Intersection> intersections = {i};
    Computation comp = prepareComputation(i, ray, intersections);
    ASSERT_TRUE(comp.reflectv == Tuple::Vector(0.0f, sqrt(2.0f)/2.0f, sqrt(2.0f)/2.0f));
}


TEST(Computation_test, calculates_n1_and_n2_at_different_intersections) {
    Sphere A = Sphere::GlassSphere();
    A.setTransformation(scaling(2.0f, 2.0f, 2.0f));
    A.material.refractive_index = 1.5f;

    Sphere B = Sphere::GlassSphere();
    B.setTransformation(translation(0.0f, 0.0f, -0.25));
    B.material.refractive_index = 2.0f;

    Sphere C = Sphere::GlassSphere();
    C.setTransformation(translation(0.0f, 0.0f, 0.25));
    C.material.refractive_index = 2.5f;

    Ray ray(Tuple::Point(0.0f, 0.0f, -4.0f), Tuple::Vector(0.0f, 0.0f, 1.0f));

    Intersection a1(A, 2.0f);
    Intersection b1(B, 2.75f);
    Intersection c1(C, 3.25f);
    Intersection b2(B, 4.75f);
    Intersection c2(C, 5.25f);
    Intersection a2(A, 6.0f);

    std::vector<Intersection> intersections = {a1, b1, c1, b2, c2, a2};

    Computation comp1 = prepareComputation(intersections[0], ray, intersections);
    ASSERT_EQ(comp1.n1, 1.0f);
    ASSERT_EQ(comp1.n2, 1.5f);

    Computation comp2 = prepareComputation(intersections[1], ray, intersections);
    ASSERT_EQ(comp2.n1, 1.5f);
    ASSERT_EQ(comp2.n2, 2.0f);

    Computation comp3 = prepareComputation(intersections[2], ray, intersections);
    ASSERT_EQ(comp3.n1, 2.0f);
    ASSERT_EQ(comp3.n2, 2.5f);

    Computation comp4 = prepareComputation(intersections[3], ray, intersections);
    ASSERT_EQ(comp4.n1, 2.5f);
    ASSERT_EQ(comp4.n2, 2.5f);

    Computation comp5 = prepareComputation(intersections[4], ray, intersections);
    ASSERT_EQ(comp5.n1, 2.5f);
    ASSERT_EQ(comp5.n2, 1.5f);

    Computation comp6 = prepareComputation(intersections[5], ray, intersections);
    ASSERT_EQ(comp6.n1, 1.5f);
    ASSERT_EQ(comp6.n2, 1.0f);
}

TEST(Comptatuion_test, shlick_approximation_under_total_internal_reflection) {
    Sphere sphere = Sphere::GlassSphere();
    Ray ray(Tuple::Point(0.0f, 0.0f, sqrt(2.0f)/2.0f), Tuple::Vector(0.0f, 1.0f, 0.0f));

    Intersection i1(sphere, -sqrt(2.0f)/2.0f);
    Intersection i2(sphere, sqrt(2.0f)/2.0f);

    std::vector<Intersection> intersections = {i1, i2};

    Computation comp = prepareComputation(intersections[1], ray, intersections);

    float reflectance = shlick(comp);

    ASSERT_EQ(reflectance, 1.0f);
}

TEST(Comptatuion_test, shlick_approximation_with_perpendicular_view_angle) {
    Sphere sphere = Sphere::GlassSphere();
    Ray ray(Tuple::Point(0.0f, 0.0f, 0.0f), Tuple::Vector(0.0f, 1.0f, 0.0f));

    Intersection i1(sphere, -1.0f);
    Intersection i2(sphere, 1.0f);

    std::vector<Intersection> intersections = {i1, i2};

    Computation comp = prepareComputation(intersections[1], ray, intersections);

    float reflectance = shlick(comp);

    ASSERT_TRUE((reflectance-0.04f) < EPSILON && (reflectance-0.04f) > -EPSILON);
}

TEST(Comptatuion_test, shlick_approximation_with_small_angle_and_n2_greater_than_n1) {
    Sphere sphere = Sphere::GlassSphere();
    Ray ray(Tuple::Point(0.0f, 0.99f, -2.0f), Tuple::Vector(0.0f, 0.0f, 1.0f));

    Intersection i(sphere, 1.8589f);

    std::vector<Intersection> intersections = {i};

    Computation comp = prepareComputation(intersections[0], ray, intersections);

    float reflectance = shlick(comp);

    ASSERT_TRUE((reflectance - 0.48873f) < EPSILON && (reflectance - 0.48873f) > -EPSILON);

}