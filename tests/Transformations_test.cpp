#define _USE_MATH_DEFINES

#include <gtest/gtest.h>
#include <cmath>

#include "Tuple.h"
#include "Matrix.h"
#include "Transformations.h"

TEST(Transformations_test, translation_matrix_applied_to_a_point_moves_it) {
    Matrix transform = translation(5.0f, -3.0f, 2.0f);
    Tuple point = Tuple::Point(-3.0f, 4.0f, 5.0f);

    Tuple expected = Tuple::Point(2.0f, 1.0f, 7.0f);
    Tuple result = transform * point;   

    ASSERT_TRUE(result == expected);
}

TEST(Transformations_test, inverse_of_translation_times_point_moves_it_in_reverse) {
    Matrix transform = translation(5.0f, -3.0f, 2.0f);
    Tuple point = Tuple::Point(-3.0f, 4.0f, 5.0f);

    Matrix inv = inverse(transform);

    Tuple expected = Tuple::Point(-8.0f, 7.0f, 3.0f);
    Tuple result = inv * point;   

    ASSERT_TRUE(result == expected);
}

TEST(Transformations_test, translation_does_not_effect_vectors) {
    Matrix transform = translation(5.0f, -3.0f, 2.0f);
    Tuple vector = Tuple::Vector(-3.0f, 4.0f, 5.0f);

    Matrix inv = inverse(transform);

    Tuple result = inv * vector;   

    ASSERT_TRUE(result == vector);
}

TEST(Transformations_test, scaling_matrix_applied_to_a_point_scales_it) {
    Matrix transform = scaling(2.0f, 3.0f, 4.0f);
    Tuple point = Tuple::Point(-4.0f, 6.0f, 8.0f);

    Tuple expected = Tuple::Point(-8.0f, 18.0f, 32.0f);
    Tuple result = transform * point;   

    ASSERT_TRUE(result == expected);
}

TEST(Transformations_test, scaling_matrix_applied_to_a_vector_scales_it) {
    Matrix transform = scaling(2.0f, 3.0f, 4.0f);
    Tuple vector = Tuple::Vector(-4.0f, 6.0f, 8.0f);

    Tuple expected = Tuple::Vector(-8.0f, 18.0f, 32.0f);
    Tuple result = transform * vector;   

    ASSERT_TRUE(result == expected);
}

TEST(Transformations_test, inverse_of_a_scaling_matrix_applied_to_a_vector_scales_it_in_reverse) {
    Matrix transform = scaling(2.0f, 3.0f, 4.0f);
    Matrix inv = inverse(transform);

    Tuple vector = Tuple::Vector(-4.0f, 6.0f, 8.0f);

    Tuple expected = Tuple::Vector(-2.0f, 2.0f, 2.0f);
    Tuple result = inv * vector;   

    ASSERT_TRUE(result == expected);
}

TEST(Transformations_test, reflection_is_scaling_by_a_negative_value) {
    Matrix transform = scaling(-1.0f, 1.0f, 1.0f);

    Tuple point = Tuple::Point(2.0f, 3.0f, 4.0f);

    Tuple expected = Tuple::Point(-2.0f, 3.0f, 4.0f);
    Tuple result = transform * point;   

    ASSERT_TRUE(result == expected);
}

TEST(Transformations_test, rotating_a_point_around_x_axis) {
    Matrix half_quarter = rotation_x(M_PI / 4.0f);
    Matrix full_quarter = rotation_x(M_PI / 2.0f);

    Tuple point = Tuple::Point(0.0f, 1.0f, 0.0f);

    Tuple expected1 = Tuple::Point(0.0f, sqrt(2.0f) / 2.0f, sqrt(2.0f) / 2.0f);
    Tuple result1 = half_quarter * point;  

    Tuple expected2 = Tuple::Point(0.0f, 0.0f, 1.0f);
    Tuple result2 = full_quarter * point;  

    ASSERT_TRUE(result1 == expected1);
    ASSERT_TRUE(result2 == expected2);
}

TEST(Transformations_test, inverse_of_an_x_rotation_rotates_in_the_opposite_direction) {
    Matrix half_quarter = rotation_x(M_PI / 4.0f);
    Matrix inv = inverse(half_quarter);

    Tuple point = Tuple::Point(0.0f, 1.0f, 0.0f);

    Tuple expected1 = Tuple::Point(0.0f, sqrt(2.0f) / 2.0f, -sqrt(2.0f) / 2.0f);
    Tuple result1 = inv * point;  

    ASSERT_TRUE(result1 == expected1);
}

TEST(Transformations_test, rotating_a_point_around_y_axis) {
    Matrix half_quarter = rotation_y(M_PI / 4.0f);
    Matrix full_quarter = rotation_y(M_PI / 2.0f);

    Tuple point = Tuple::Point(0.0f, 0.0f, 1.0f);

    Tuple expected1 = Tuple::Point(sqrt(2.0f) / 2.0f, 0.0f, sqrt(2.0f) / 2.0f);
    Tuple result1 = half_quarter * point;  

    Tuple expected2 = Tuple::Point(1.0f, 0.0f, 0.0f);
    Tuple result2 = full_quarter * point;  

    ASSERT_TRUE(result1 == expected1);
    ASSERT_TRUE(result2 == expected2);
}

TEST(Transformations_test, rotating_a_point_around_z_axis) {
    Matrix half_quarter = rotation_z(M_PI / 4.0f);
    Matrix full_quarter = rotation_z(M_PI / 2.0f);

    Tuple point = Tuple::Point(0.0f, 1.0f, 0.0f);

    Tuple expected1 = Tuple::Point(-sqrt(2.0f) / 2.0f, sqrt(2.0f) / 2.0f, 0.0f);
    Tuple result1 = half_quarter * point;  

    Tuple expected2 = Tuple::Point(-1.0f, 0.0f, 0.0f);
    Tuple result2 = full_quarter * point;  

    ASSERT_TRUE(result1 == expected1);
    ASSERT_TRUE(result2 == expected2);
}

TEST(Transformations_test, shearing_transformation_moves_x_in_proportion_to_y) {
    Matrix transform = shearing(1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    Tuple point = Tuple::Point(2.0f, 3.0f, 4.0f);

    Tuple expected = Tuple::Point(5.0f, 3.0f, 4.0f);
    Tuple result = transform * point;
    ASSERT_TRUE(result == expected);
}

TEST(Transformations_test, shearing_transformation_moves_x_in_proportion_to_z) {
    Matrix transform = shearing(0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    Tuple point = Tuple::Point(2.0f, 3.0f, 4.0f);

    Tuple expected = Tuple::Point(6.0f, 3.0f, 4.0f);
    Tuple result = transform * point;
    ASSERT_TRUE(result == expected);
}

TEST(Transformations_test, shearing_transformation_moves_y_in_proportion_to_x) {
    Matrix transform = shearing(0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f);
    Tuple point = Tuple::Point(2.0f, 3.0f, 4.0f);

    Tuple expected = Tuple::Point(2.0f, 5.0f, 4.0f);
    Tuple result = transform * point;
    ASSERT_TRUE(result == expected);
}

TEST(Transformations_test, shearing_transformation_moves_y_in_proportion_to_z) {
    Matrix transform = shearing(0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f);
    Tuple point = Tuple::Point(2.0f, 3.0f, 4.0f);

    Tuple expected = Tuple::Point(2.0f, 7.0f, 4.0f);
    Tuple result = transform * point;
    ASSERT_TRUE(result == expected);
}

TEST(Transformations_test, shearing_transformation_moves_z_in_proportion_to_x) {
    Matrix transform = shearing(0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    Tuple point = Tuple::Point(2.0f, 3.0f, 4.0f);

    Tuple expected = Tuple::Point(2.0f, 3.0f, 6.0f);
    Tuple result = transform * point;
    ASSERT_TRUE(result == expected);
}

TEST(Transformations_test, shearing_transformation_moves_z_in_proportion_to_y) {
    Matrix transform = shearing(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f);
    Tuple point = Tuple::Point(2.0f, 3.0f, 4.0f);

    Tuple expected = Tuple::Point(2.0f, 3.0f, 7.0f);
    Tuple result = transform * point;
    ASSERT_TRUE(result == expected);
}

TEST(Transformations_test, chained_transformations) {
    Tuple point = Tuple::Point(1.0f, 0.0f, 1.0f);

    Matrix A = rotation_x(M_PI / 2.0f);
    Matrix B = scaling(5.0f, 5.0f, 5.0f);
    Matrix C = translation(10.0f, 5.0f, 7.0f);

    Matrix T = C*B*A;

    Tuple expected = Tuple::Point(15.0f, 0.0f, 7.0f);
    Tuple result = T * point;

    ASSERT_TRUE(expected == result);
}

TEST(Transformation_test, view_transformation_matrix_for_default_orientation) {
    Tuple from = Tuple::Point(0.0f, 0.0f, 0.0f);
    Tuple to = Tuple::Point(0.0f, 0.0f, -1.0f);
    Tuple up = Tuple::Vector(0.0f, 1.0f, 0.0f);

    Matrix t = viewTransformation(from, to, up);
    Matrix I = Matrix::Identity(4);
    ASSERT_TRUE(t == I);
}

TEST(Transformation_test, view_transformation_matrix_looking_in_positive_z_direction) {
    Tuple from = Tuple::Point(0.0f, 0.0f, 0.0f);
    Tuple to = Tuple::Point(0.0f, 0.0f, 1.0f);
    Tuple up = Tuple::Vector(0.0f, 1.0f, 0.0f);

    Matrix t = viewTransformation(from, to, up);
    ASSERT_TRUE(t == scaling(-1.0f, 1.0f, -1.0f));
}

TEST(Transformation_test, view_transformation_matrix_moves_the_world) {
    Tuple from = Tuple::Point(0.0f, 0.0f, 8.0f);
    Tuple to = Tuple::Point(0.0f, 0.0f, 0.0f);
    Tuple up = Tuple::Vector(0.0f, 1.0f, 0.0f);

    Matrix t = viewTransformation(from, to, up);

    ASSERT_TRUE(t == translation(0.0f, 0.0f, -8.0f));
}

TEST(Transformation_test, arbitrary_view_transformation) {
    Tuple from = Tuple::Point(1.0f, 3.0f, 2.0f);
    Tuple to = Tuple::Point(4.0f, -2.0f, 8.0f);
    Tuple up = Tuple::Vector(1.0f, 1.0f, 0.0f);

    Matrix t = viewTransformation(from, to, up);

    Matrix expected(
        -0.50709f, 0.50709f, 0.67612f, -2.36643f,
        0.76772f, 0.60609f, 0.12122f, -2.82843f,
        -0.35857f, 0.59761f, -0.71714f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    );
    ASSERT_TRUE(t == expected);
}