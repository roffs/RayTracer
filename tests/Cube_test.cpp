#include <gtest/gtest.h>

#include "Cube.h"
#include "Ray.h"
#include "Tuple.h"

TEST(Cube_test, a_ray_intersects_a_cube) {
    Cube cube;

    //+x
    Tuple origin = Tuple::Point(5.0f, 0.5f, 0.0f);
    Tuple direction = Tuple::Vector(-1.0f, 0.0f, 0.0f);
    Ray ray(origin, direction);

    std::vector<Intersection> intersections = cube.localIntersects(ray);
    ASSERT_EQ(intersections.size(), 2);
    ASSERT_EQ(intersections[0].t, 4.0f);
    ASSERT_EQ(intersections[1].t, 6.0f);

    //-x
    origin = Tuple::Point(-5.0f, 0.5f, 0.0f);
    direction = Tuple::Vector(1.0f, 0.0f, 0.0f);
    ray = Ray(origin, direction);

    intersections = cube.localIntersects(ray);
    ASSERT_EQ(intersections.size(), 2);
    ASSERT_EQ(intersections[0].t, 4.0f);
    ASSERT_EQ(intersections[1].t, 6.0f);

    //y
    origin = Tuple::Point(0.5f, 5.0f, 0.0f);
    direction = Tuple::Vector(0.0f, -1.0f, 0.0f);
    ray = Ray(origin, direction);

    intersections = cube.localIntersects(ray);
    ASSERT_EQ(intersections.size(), 2);
    ASSERT_EQ(intersections[0].t, 4.0f);
    ASSERT_EQ(intersections[1].t, 6.0f);

    //-y
    origin = Tuple::Point(0.5f, -5.0f, 0.0f);
    direction = Tuple::Vector(0.0f, 1.0f, 0.0f);
    ray = Ray(origin, direction);

    intersections = cube.localIntersects(ray);
    ASSERT_EQ(intersections.size(), 2);
    ASSERT_EQ(intersections[0].t, 4.0f);
    ASSERT_EQ(intersections[1].t, 6.0f);

    //z
    origin = Tuple::Point(0.5f, 0.0f, 5.0f);
    direction = Tuple::Vector(0.0f, 0.0f, -1.0f);
    ray = Ray(origin, direction);

    intersections = cube.localIntersects(ray);
    ASSERT_EQ(intersections.size(), 2);
    ASSERT_EQ(intersections[0].t, 4.0f);
    ASSERT_EQ(intersections[1].t, 6.0f);

    //-z
    origin = Tuple::Point(0.5f, 0.0f, -5.0f);
    direction = Tuple::Vector(0.0f, 0.0f, 1.0f);
    ray = Ray(origin, direction);

    intersections = cube.localIntersects(ray);
    ASSERT_EQ(intersections.size(), 2);
    ASSERT_EQ(intersections[0].t, 4.0f);
    ASSERT_EQ(intersections[1].t, 6.0f);

    //inside
    origin = Tuple::Point(0.0f, 0.5f, 0.0f);
    direction = Tuple::Vector(0.0f, 0.0f, 1.0f);
    ray = Ray(origin, direction);

    intersections = cube.localIntersects(ray);
    ASSERT_EQ(intersections.size(), 2);
    ASSERT_EQ(intersections[0].t, -1.0f);
    ASSERT_EQ(intersections[1].t, 1.0f);
}

TEST(Cube_test, a_ray_misses_the_cube) { 
    Cube cube;

    //-------------------
    Tuple origin = Tuple::Point(-2.0f, 0.0f, 0.0f);
    Tuple direction = Tuple::Vector(0.2673f, 0.5345f, 0.8018f);
    Ray ray(origin, direction);
    std::vector<Intersection> intersections = cube.localIntersects(ray);
    ASSERT_EQ(intersections.size(), 0);

    //-------------------
    origin = Tuple::Point(0.0f, -2.0f, 0.0f);
    direction = Tuple::Vector(0.8018f, 0.2673f, 0.5345f);
    ray = Ray(origin, direction);
    intersections = cube.localIntersects(ray);
    ASSERT_EQ(intersections.size(), 0);
    
    //-------------------
    origin = Tuple::Point(0.0f, 0.0f, -2.0f);
    direction = Tuple::Vector(0.5345f, 0.8018f, 0.2673f);
    ray = Ray(origin, direction);
    intersections = cube.localIntersects(ray);
    ASSERT_EQ(intersections.size(), 0);
    
    //-------------------
    origin = Tuple::Point(2.0f, 0.0f, 2.0f);
    direction = Tuple::Vector(0.0f, 0.0f, -1.0f);
    ray = Ray(origin, direction);
    intersections = cube.localIntersects(ray);
    ASSERT_EQ(intersections.size(), 0);

    //-------------------
    origin = Tuple::Point(0.0f, 2.0f, 2.0f);
    direction = Tuple::Vector(0.0f, -1.0f, 0.0f);
    ray = Ray(origin, direction);
    intersections = cube.localIntersects(ray);
    ASSERT_EQ(intersections.size(), 0);

    //-------------------
    origin = Tuple::Point(2.0f, 2.0f, 0.0f);
    direction = Tuple::Vector(-1.0f, 0.0f, 0.0f);
    ray = Ray(origin, direction);
    intersections = cube.localIntersects(ray);
    ASSERT_EQ(intersections.size(), 0);
}

TEST(Cube_test, normal_on_the_surface_of_the_cube) { 
    Cube cube;

    Tuple point = Tuple::Point(1.0f, 0.5f, -0.8f);
    Tuple actualNormal = cube.localNormalAt(point);
    Tuple expectedNormal = Tuple::Vector(1.0f, 0.0f, 0.0f);
    ASSERT_TRUE(actualNormal == expectedNormal);

    //------------------- 
    point = Tuple::Point(-1.0f, -0.2f, 0.9f);
    actualNormal = cube.localNormalAt(point);
    expectedNormal = Tuple::Vector(-1.0f, 0.0f, 0.0f);
    ASSERT_TRUE(actualNormal == expectedNormal);

    //-------------------
    point = Tuple::Point(-0.4f, 1.0f, -0.1);
    actualNormal = cube.localNormalAt(point);
    expectedNormal = Tuple::Vector(0.0f, 1.0f, 0.0f);
    ASSERT_TRUE(actualNormal == expectedNormal);

    //-------------------
    point = Tuple::Point(0.3f, -1.0f, -0.7f);
    actualNormal = cube.localNormalAt(point);
    expectedNormal = Tuple::Vector(0.0f, -1.0f, 0.0f);
    ASSERT_TRUE(actualNormal == expectedNormal);

    //-------------------
    point = Tuple::Point(-0.6f, 0.3f, 1.0f);
    actualNormal = cube.localNormalAt(point);
    expectedNormal = Tuple::Vector(0.0f, 0.0f, 1.0f);
    ASSERT_TRUE(actualNormal == expectedNormal);

    //-------------------
    point = Tuple::Point(0.4f, 0.4f, -1.0f);
    actualNormal = cube.localNormalAt(point);
    expectedNormal = Tuple::Vector(0.0f, 0.0f, -1.0f);
    ASSERT_TRUE(actualNormal == expectedNormal);

    //-------------------
    point = Tuple::Point(1.0f, 1.0f, 1.0f);
    actualNormal = cube.localNormalAt(point);
    expectedNormal = Tuple::Vector(1.0f, 0.0f, 0.0f);
    ASSERT_TRUE(actualNormal == expectedNormal);

    //-------------------
    point = Tuple::Point(-1.0f, -1.0f, -1.0f);
    actualNormal = cube.localNormalAt(point);
    expectedNormal = Tuple::Vector(-1.0f, 0.0f, 0.0f);
    ASSERT_TRUE(actualNormal == expectedNormal);
}