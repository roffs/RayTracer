#include <gtest/gtest.h>
#include <limits>
#include <iostream>

#include "Tuple.h"
#include "Ray.h"
#include "Sphere.h"
#include "Intersection.h"
#include "Matrix.h"
#include "Transformations.h"

TEST(Ray_test, creates_ray_from_point_and_direction) {
    Tuple origin = Tuple::Point(1.0f, 2.0f, 3.0f);
    Tuple direction = Tuple::Vector(4.0f, 5.0f, 6.0f);

    Ray ray(origin, direction);
    ASSERT_TRUE(ray.origin == origin);
    ASSERT_TRUE(ray.direction == direction);
}

TEST(Ray_test, computes_a_point_from_a_ray_and_its_direction) {
    Tuple origin = Tuple::Point(2.0f, 3.0f, 4.0f);
    Tuple direction = Tuple::Vector(1.0f, 0.0f, 0.0f);

    Ray ray(origin, direction);
    
    Tuple result1 = Tuple::Point(2.0f, 3.0f, 4.0f);
    Tuple result2 = Tuple::Point(3.0f, 3.0f, 4.0f);
    Tuple result3 = Tuple::Point(1.0f, 3.0f, 4.0f);
    Tuple result4 = Tuple::Point(4.5f, 3.0f, 4.0f);

    Tuple expected1 = position(ray, 0.0f);
    Tuple expected2 = position(ray, 1.0f);
    Tuple expected3 = position(ray, -1.0f);
    Tuple expected4 = position(ray, 2.5f);

    ASSERT_TRUE(expected1 == result1);
    ASSERT_TRUE(expected2 == result2);
    ASSERT_TRUE(expected3 == result3);
    ASSERT_TRUE(expected4 == result4);
}

TEST(Ray_test, ray_intersects_sphere_at_two_points) {
    Tuple origin = Tuple::Point(0.0f, 0.0f, -5.0f);
    Tuple direction = Tuple::Vector(0.0f, 0.0f, 1.0f);    
    Ray ray(origin, direction);

    Sphere sphere; 

    std::vector<Intersection> intersections = sphere.intersects(ray);

    ASSERT_EQ(intersections[0].t, 4.0f);
    ASSERT_EQ(intersections[1].t, 6.0f);
}

TEST(Ray_test, ray_intersects_tangent_sphere) {
    Tuple origin = Tuple::Point(0.0f, 1.0f, -5.0f);
    Tuple direction = Tuple::Vector(0.0f, 0.0f, 1.0f);    
    Ray ray(origin, direction);

    Sphere sphere; 

    std::vector<Intersection> intersections = sphere.intersects(ray);

    ASSERT_EQ(intersections[0].t, 5.0f);
    ASSERT_EQ(intersections[1].t, 5.0f);
}

TEST(Ray_test, ray_misses_a_sphere) {
    Tuple origin = Tuple::Point(0.0f, 2.0f, -5.0f);
    Tuple direction = Tuple::Vector(0.0f, 0.0f, 1.0f);    
    Ray ray(origin, direction);

    Sphere sphere; 

    std::vector<Intersection> intersections = sphere.intersects(ray);

    ASSERT_EQ(intersections.size(), 0);
}

TEST(Ray_test, ray_with_origin_inside_sphere_intersects_with_it) {
    Tuple origin = Tuple::Point(0.0f, 0.0f, 0.0f);
    Tuple direction = Tuple::Vector(0.0f, 0.0f, 1.0f);    
    Ray ray(origin, direction);

    Sphere sphere; 

    std::vector<Intersection> intersections = sphere.intersects(ray);

    ASSERT_EQ(intersections[0].t, -1.0f);
    ASSERT_EQ(intersections[1].t, 1.0f);
    ASSERT_TRUE(intersections[0].object == &sphere);
    ASSERT_TRUE(intersections[1].object == &sphere);
}

TEST(Ray_test, translating_a_ray) {
    Tuple origin = Tuple::Point(1.0f, 2.0f, 3.0f);
    Tuple direction = Tuple::Vector(0.0f, 1.0f, 0.0f);    
    Ray ray(origin, direction);

    Matrix transf = translation(3.0f, 4.0f, 5.0f);
    Ray result = transformRay(ray, transf);    

    Tuple expectedOrigin = Tuple::Point(4.0f, 6.0f, 8.0f);
    Tuple expectedDirection = Tuple::Vector(0.0f, 1.0f, 0.0f);

    ASSERT_TRUE(result.origin == expectedOrigin);
    ASSERT_TRUE(result.direction == expectedDirection);
}

TEST(Ray_test, scaling_a_ray) {
    Tuple origin = Tuple::Point(1.0f, 2.0f, 3.0f);
    Tuple direction = Tuple::Vector(0.0f, 1.0f, 0.0f);    
    Ray ray(origin, direction);

    Matrix transf = scaling(2.0f, 3.0f, 4.0f);
    Ray result = transformRay(ray, transf);
    
    Tuple expectedOrigin = Tuple::Point(2.0f, 6.0f, 12.0f);
    Tuple expectedDirection = Tuple::Vector(0.0f, 3.0f, 0.0f);

    ASSERT_TRUE(result.origin == expectedOrigin);
    ASSERT_TRUE(result.direction == expectedDirection);
}

TEST(Ray_test, intersect_a_scaled_sphere_with_a_ray) {
    Tuple origin = Tuple::Point(0.0f, 0.0f, -5.0f);
    Tuple direction = Tuple::Vector(0.0f, 0.0f, 1.0f);    
    Ray ray(origin, direction);

    Sphere sphere;

    sphere.setTransformation(scaling(2.0f, 2.0f, 2.0f));

    std::vector<Intersection> intersections = sphere.intersects(ray);

    ASSERT_EQ(intersections[0].t, 3.0f);
    ASSERT_EQ(intersections[1].t, 7.0f);
}

TEST(Ray_test, intersect_a_translated_sphere_with_a_ray) {
    Tuple origin = Tuple::Point(0.0f, 0.0f, -5.0f);
    Tuple direction = Tuple::Vector(0.0f, 0.0f, 1.0f);    
    Ray ray(origin, direction);

    Sphere sphere;

    sphere.setTransformation(translation(5.0f, 0.0f, 0.0f));

    std::vector<Intersection> intersections = sphere.intersects(ray);

    ASSERT_EQ(intersections.size(), 0);
}
