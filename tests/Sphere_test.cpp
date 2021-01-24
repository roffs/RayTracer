#define _USE_MATH_DEFINES
#include <gtest/gtest.h>
#include <cmath>

#include "Sphere.h"
#include "Tuple.h"
#include "Matrix.h"
#include "Transformations.h"

TEST(Sphere_test, construct_default_sphere) {
    Tuple center = Tuple::Point(0.0f, 0.0f, 0.0f);
    float radius = 1.0f;

    Sphere sphere;

    Matrix I = identity(4);

    ASSERT_TRUE(sphere.center == center);
    ASSERT_EQ(sphere.radius, radius);
    ASSERT_TRUE(sphere.transform == I);
}

TEST(Sphere_test, set_desired_transformation_to_sphere) {
    Sphere sphere;
    Matrix transform = translation(2.0f, 3.0f, 4.0f);

    sphere.setTransformation(transform);

    ASSERT_TRUE(sphere.transform == transform);
}

TEST(Sphere_test, calculate_normal_on_a_sphere_at_a_point_on_the_x_axis) {
    Sphere sphere;
    Tuple point = Tuple::Point(1.0f, 0.0f, 0.0f);

    Tuple n = sphere.normal(point);
    Tuple expected = Tuple::Vector(1.0f, 0.0f, 0.0f);

    ASSERT_TRUE(n == expected);
}

TEST(Sphere_test, calculate_normal_on_a_sphere_at_a_point_on_the_y_axis) {
    Sphere sphere;
    Tuple point = Tuple::Point(0.0f, 1.0f, 0.0f);

    Tuple n = sphere.normal(point);
    Tuple expected = Tuple::Vector(0.0f, 1.0f, 0.0f);
    
    ASSERT_TRUE(n == expected);
}

TEST(Sphere_test, calculate_normal_on_a_sphere_at_a_point_on_the_z_axis) {
    Sphere sphere;
    Tuple point = Tuple::Point(0.0f, 0.0f, 1.0f);

    Tuple n = sphere.normal(point);
    Tuple expected = Tuple::Vector(0.0f, 0.0f, 1.0f);
    
    ASSERT_TRUE(n == expected);
}

TEST(Sphere_test, calculate_normal_on_a_sphere_at_a_nonaxial_point) {
    Sphere sphere;
    Tuple point = Tuple::Point(sqrt(3.0f)/3.0f, sqrt(3)/3.0f, sqrt(3)/3.0f);

    Tuple n = sphere.normal(point);
    Tuple expected = Tuple::Vector(sqrt(3)/3.0f, sqrt(3)/3.0f, sqrt(3)/3.0f);
    
    ASSERT_TRUE(n == expected);
}

TEST(Sphere_test, calculate_normal_on_a_translated_sphere) {
    Sphere sphere;
    sphere.setTransformation(translation(0.0f, 1.0f, 0.0f));

    Tuple point = Tuple::Point(0.0f, 1.70711f, -0.70711f);

    Tuple n = sphere.normal(point);
    Tuple expected = Tuple::Vector(0.0f, 0.70711f, -0.70711f);
    
    ASSERT_TRUE(n == expected);
}

TEST(Sphere_test, calculate_normal_on_a_transformedsphere) {
    Sphere sphere;
    sphere.setTransformation(scaling(1.0f, 0.5f, 1.0f) * rotation_z(M_PI/5.0f));

    Tuple point = Tuple::Point(0.0f, sqrt(2.0f)/2.0f, -sqrt(2.0f)/2.0f);

    Tuple n = sphere.normal(point);
    Tuple expected = Tuple::Vector(0.0f, 0.97014f, -0.24254);
    
    ASSERT_TRUE(n == expected);
}