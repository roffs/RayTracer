#include <gtest/gtest.h>

#define _USE_MATH_DEFINES
#include <cmath>

#include "Camera.h"
#include "Ray.h"
#include "Transformations.h"
#include "World.h"
#include "Canvas.h"

TEST(Camera_test, construct_a_camera) {
    int hsize = 160;
    int vsize = 120;
    float fieldOfView = M_PI/2.0f;
    Camera camera(hsize, vsize, fieldOfView);

    ASSERT_EQ(camera.hsize, hsize);
    ASSERT_EQ(camera.vsize, vsize);
    ASSERT_EQ(camera.fieldOfView, fieldOfView);
    ASSERT_TRUE(camera.transform == Matrix::Identity(4));
}

TEST(Camera_test, pixel_size_for_horizontal_canvas) {
    Camera camera(200, 125, M_PI/2.0f);

    ASSERT_EQ(camera.pixelSize, 0.01f);
}

TEST(Camera_test, pixel_size_for_vertical_canvas) {
    Camera camera(125, 200, M_PI/2.0f);

    ASSERT_EQ(camera.pixelSize, 0.01f);
}

TEST(Camera_test, construct_a_ray_through_the_center_of_the_canvas) {
    Camera camera(201, 101, M_PI/2.0f);
    Ray ray = camera.rayForPixel(100, 50);

    ASSERT_TRUE(ray.origin == Tuple::Point(0.0f, 0.0f, 0.0f));
    ASSERT_TRUE(ray.direction == Tuple::Vector(0.0f, 0.0f, -1.0f));
}

TEST(Camera_test, construct_a_ray_through_a_corner_of_the_canvas) {
    Camera camera(201, 101, M_PI/2.0f);
    Ray ray = camera.rayForPixel(0, 0);

    ASSERT_TRUE(ray.origin == Tuple::Point(0.0f, 0.0f, 0.0f));
    ASSERT_TRUE(ray.direction == Tuple::Vector(0.66519f, 0.33259f, -0.66851f));
}

TEST(Camera_test, construct_a_ray_when_camera_is_transformed) {
    Camera camera(201, 101, M_PI/2.0f);
    camera.transform = rotation_y(M_PI/4.0f) * translation(0.0f, -2.0f, 5.0f);
    Ray ray = camera.rayForPixel(100, 50);

    ASSERT_TRUE(ray.origin == Tuple::Point(0.0f, 2.0f, -5.0f));
    ASSERT_TRUE(ray.direction == Tuple::Vector(sqrt(2.0f)/2.0f, 0.0f, -sqrt(2.0f)/2.0f));
}

TEST(Camera_test, render_a_default_world_with_a_camera) {
    World world = World::DefaultWorld();
    Camera camera(11, 11, M_PI/2);

    Tuple from = Tuple::Point(0.0f, 0.0f, -5.0f);
    Tuple to = Tuple::Point(0.0f, 0.0f, 0.0f);
    Tuple up = Tuple::Vector(0.0f, 1.0f, 0.0f);
    camera.transform = viewTransformation(from, to, up);

    Canvas image = render(camera, world);
    Color result = image.pixelAt(5, 5);
    Color expectedColor(0.38066f, 0.47583f, 0.2855f);
    ASSERT_TRUE(image.pixelAt(5, 5) == expectedColor);
}