#include <gtest/gtest.h>

#include <iostream>

#include "Matrix.h"
#include "Tuple.h"

TEST(Matrix_test, constructor_creates_4x4_matrix_with_specified_values) {
    Matrix matrix(
        1.0f, 2.0f, 3.0f, 4.0f,
        5.5f, 6.5f, 7.5f, 8.5f,
        9.0f, 10.0f, 11.0f, 12.0f,
        13.5f, 14.5f, 15.5f, 16.5f
    );
    
    ASSERT_EQ(matrix(0, 0), 1.0f);
    ASSERT_EQ(matrix(0, 1), 2.0f);
    ASSERT_EQ(matrix(0, 2), 3.0f);
    ASSERT_EQ(matrix(0, 3), 4.0f);

    ASSERT_EQ(matrix(1, 0), 5.5f);
    ASSERT_EQ(matrix(1, 1), 6.5f);
    ASSERT_EQ(matrix(1, 2), 7.5f);
    ASSERT_EQ(matrix(1, 3), 8.5f);

    ASSERT_EQ(matrix(2, 0), 9.0f);
    ASSERT_EQ(matrix(2, 1), 10.0f);
    ASSERT_EQ(matrix(2, 2), 11.0f);
    ASSERT_EQ(matrix(2, 3), 12.0f);
    
    ASSERT_EQ(matrix(3, 0), 13.5f);
    ASSERT_EQ(matrix(3, 1), 14.5f);
    ASSERT_EQ(matrix(3, 2), 15.5f);
    ASSERT_EQ(matrix(3, 3), 16.5f);
}

TEST(Matrix_test, constructor_creates_3x3_matrix_with_specified_values) {
    Matrix matrix(
        -3.0f, 5.0f, 0.0f,
        1.0f, -2.0f, -7.0f,
        1.0f, 1.0f, 1.0f
    );
    
    ASSERT_EQ(matrix(0, 0), -3.0);
    ASSERT_EQ(matrix(0, 1), 5.0f);
    ASSERT_EQ(matrix(0, 2), 0.0f);

    ASSERT_EQ(matrix(1, 0), 1.0f);
    ASSERT_EQ(matrix(1, 1), -2.0f);
    ASSERT_EQ(matrix(1, 2), -7.0f);

    ASSERT_EQ(matrix(2, 0), 1.0f);
    ASSERT_EQ(matrix(2, 1), 1.0f);
    ASSERT_EQ(matrix(2, 2), 1.0f);
}

TEST(Matrix_test, constructor_creates_2x2_matrix_with_specified_values) {
    Matrix matrix(-3.0f, 5.0f, 1.0f, -2.0f);
    
    ASSERT_EQ(matrix(0, 0), -3.0f);
    ASSERT_EQ(matrix(0, 1), 5.0f);

    ASSERT_EQ(matrix(1, 0), 1.0);
    ASSERT_EQ(matrix(1, 1), -2.0f);
}

TEST(Matrix_test, access_operator_overload_for_retrieve_and_assign){
    Matrix matrix(-3.0f, 5.0f, 1.0f, -2.0f);
    matrix(0, 1) = 4.0f;

    ASSERT_EQ(matrix(0, 0), -3.0f);
    ASSERT_EQ(matrix(0, 1), 4.0f);
}

TEST(Matrix_test, equal_operator_overload) {
    Matrix matrix1(-3.0f, 5.0f, 1.0f, -2.0f);
    Matrix matrix2(-3.0f, 5.0f, 1.0f, -2.0f);
    Matrix matrix3(-1.0f, 1.0f, 1.0f, -2.0f);

    ASSERT_TRUE(matrix1 == matrix2);
    ASSERT_FALSE(matrix1 != matrix2);
    ASSERT_FALSE(matrix1 == matrix3);
    ASSERT_TRUE(matrix1 != matrix3);
}

TEST(Matrix_test, comparing_matrix_with_different_dimensions) {
    Matrix matrix1(-3.0f, 5.0f, 1.0f, -2.0f);
    Matrix matrix2(
        -3.0f, 5.0f, 1.0f, 
        -3.0f, 5.0f, 1.0f, 
        -3.0f, 5.0f, 1.0f
    );

    ASSERT_TRUE(matrix1 != matrix2);
    ASSERT_FALSE(matrix1 == matrix2);
}

TEST(Matrix_test, multiplication_matrix) {
    Matrix matrix1(
        1.0f, 2.0f, 3.0f, 4.0f,
        5.0f, 6.0f, 7.0f, 8.0f,
        9.0f, 8.0f, 7.0f, 6.0f,
        5.0f, 4.0f, 3.0f, 2.0f
    );

    Matrix matrix2(
        -2.0f, 1.0f, 2.0f, 3.0f,
        3.0f, 2.0f, 1.0, -1.0f,
        4.0f, 3.0f, 6.0f, 5.0f,
        1.0f, 2.0f, 7.0f, 8.0f
    );

    Matrix result = matrix1 * matrix2;

    ASSERT_EQ(result(0, 0), 20.0f);
    ASSERT_EQ(result(0, 1), 22.0f);
    ASSERT_EQ(result(0, 2), 50.0f);
    ASSERT_EQ(result(0, 3), 48.0f);

    ASSERT_EQ(result(1, 0), 44.0f);
    ASSERT_EQ(result(1, 1), 54.0f);
    ASSERT_EQ(result(1, 2), 114.0f);
    ASSERT_EQ(result(1, 3), 108.0f);

    ASSERT_EQ(result(2, 0), 40.0f);
    ASSERT_EQ(result(2, 1), 58.0f);
    ASSERT_EQ(result(2, 2), 110.0f);
    ASSERT_EQ(result(2, 3), 102.0f);

    ASSERT_EQ(result(3, 0), 16.0f);
    ASSERT_EQ(result(3, 1), 26.0f);
    ASSERT_EQ(result(3, 2), 46.0f);
    ASSERT_EQ(result(3, 3), 42.0f);
}

TEST(Matrix_test, multiplication_matrix_by_identity) {
    Matrix matrix(
        1.0f, 2.0f, 3.0f, 4.0f,
        5.0f, 6.0f, 7.0f, 8.0f,
        9.0f, 8.0f, 7.0f, 6.0f,
        5.0f, 4.0f, 3.0f, 2.0f
    );

    Matrix identity(
        1.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    );

    Matrix result = matrix * identity;

    ASSERT_TRUE(result == matrix);
}

TEST(Matrix_test, multiplication_matrix_by_tuple) {
    Matrix matrix(
        1.0f, 2.0f, 3.0f, 4.0f,
        2.0f, 4.0f, 4.0f, 2.0f,
        8.0f, 6.0f, 4.0f, 1.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    );

    Tuple tuple(1.0f, 2.0f, 3.0f, 1.0f);

    Tuple result = matrix * tuple;

    ASSERT_EQ(result.x, 18.0f);
    ASSERT_EQ(result.y, 24.0f);
    ASSERT_EQ(result.z, 33.0f);
    ASSERT_EQ(result.w, 1.0f);
}

TEST(Matrix_test, multiplication_matrix_by_float) {
    Matrix matrix(
        1.0f, 2.0f, 3.0f, 4.0f,
        2.0f, 4.0f, 4.0f, 2.0f,
        8.0f, 6.0f, 4.0f, 1.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    );

    Matrix result = matrix * 2.0f;

    ASSERT_EQ(result(0, 0), 2.0f);
    ASSERT_EQ(result(0, 1), 4.0f);
    ASSERT_EQ(result(0, 2), 6.0f);
    ASSERT_EQ(result(0, 3), 8.0f);

    ASSERT_EQ(result(1, 0), 4.0f);
    ASSERT_EQ(result(1, 1), 8.0f);
    ASSERT_EQ(result(1, 2), 8.0f);
    ASSERT_EQ(result(1, 3), 4.0f);

    ASSERT_EQ(result(2, 0), 16.0f);
    ASSERT_EQ(result(2, 1), 12.0f);
    ASSERT_EQ(result(2, 2), 8.0f);
    ASSERT_EQ(result(2, 3), 2.0f);

    ASSERT_EQ(result(3, 0), 0.0f);
    ASSERT_EQ(result(3, 1), 0.0f);
    ASSERT_EQ(result(3, 2), 0.0f);
    ASSERT_EQ(result(3, 3), 2.0f);
}

TEST(Matrix_test, transposing_matrix) {
    Matrix matrix(
        0.0f, 9.0f, 3.0f, 0.0f,
        9.0f, 8.0f, 0.0f, 8.0f,
        1.0f, 8.0f, 5.0f, 3.0f,
        0.0f, 0.0f, 5.0f, 8.0f
    );

    Matrix transposed(
        0.0f, 9.0f, 1.0f, 0.0f,
        9.0f, 8.0f, 8.0f, 0.0f,
        3.0f, 0.0f, 5.0f, 5.0f,
        0.0f, 8.0f, 3.0f, 8.0f
    );

    Matrix result = transpose(matrix);

    ASSERT_TRUE(result == transposed);
}

TEST(Matrix_test, 2x2_matrix_determinant) {
    Matrix matrix(1.0f, 5.0f, -3.0f, 2.0f);

    ASSERT_EQ(determinant(matrix), 17);
}

TEST(Matrix_test, submatrix_of_3x3_matrix_returns_the_matrix_with_removed_row_and_column) {
    Matrix matrix(
        1.0f, 5.0f, 0.0f,
        -3.0f, 2.0f, 7.0f,
        0.0f, 6.0f, -3.0
    );

    Matrix result = subMatrix(matrix, 0, 2);

    ASSERT_EQ(result(0, 0), -3.0f);
    ASSERT_EQ(result(0, 1), 2.0f);
    ASSERT_EQ(result(1, 0), 0.0f);
    ASSERT_EQ(result(1, 1), 6.0f);
}


TEST(Matrix_test, submatrix_of_4x4_matrix_returns_the_matrix_with_removed_row_and_column) {
    Matrix matrix(
        -6.0f, 1.0f, 1.0f, 6.0f,
        -8.0f, 5.0f, 8.0f, 6.0f,
        -1.0f, 0.0f, 8.0f, 2.0f,
        -7.0f, 1.0f, -1.0f, 1.0f
    );

    Matrix result = subMatrix(matrix, 2, 1);

    ASSERT_EQ(result(0, 0), -6.0f);
    ASSERT_EQ(result(0, 1), 1.0f);
    ASSERT_EQ(result(0, 2), 6.0f);

    ASSERT_EQ(result(1, 0), -8.0f);
    ASSERT_EQ(result(1, 1), 8.0f);
    ASSERT_EQ(result(1, 2), 6.0f);

    ASSERT_EQ(result(2, 0), -7.0f);
    ASSERT_EQ(result(2, 1), -1.0f);
    ASSERT_EQ(result(2, 2), 1.0f);
}

TEST(Matrix_test, minor_returns_the_determinant_of_the_submatrix_at_x_y) {
    Matrix matrix(
        3.0f, 5.0f, 0.0f,
        2.0f, -1.0f, -7.0f,
        6.0f, -1.0f, 5.0
    );

    Matrix submatrix = subMatrix(matrix, 1, 0);

    ASSERT_EQ(determinant(submatrix), 25.0f);
    ASSERT_EQ(minor(matrix, 1, 0), 25);
}

TEST(Matrix_test, cofactor_returns_the_minor_of_the_submatrix_at_row_col_with_correct_sign) {
    Matrix matrix(
        3.0f, 5.0f, 0.0f,
        2.0f, -1.0f, -7.0f,
        6.0f, -1.0f, 5.0
    );

    ASSERT_EQ(minor(matrix, 0, 0), -12.0f);
    ASSERT_EQ(cofactor(matrix, 0, 0), -12.0f);

    ASSERT_EQ(minor(matrix, 1, 0), 25.0f);
    ASSERT_EQ(cofactor(matrix, 1, 0), -25.0f);    
}

TEST(Matrix_test, 3x3_matrix_determinant) {
    Matrix matrix(
        1.0f, 2.0f, 6.0f,
        -5.0f, 8.0f, -4.0f,
        2.0f, 6.0f, 4.0f
    );

    ASSERT_EQ(cofactor(matrix, 0, 0), 56.0f);
    ASSERT_EQ(cofactor(matrix, 0, 1), 12.0f);
    ASSERT_EQ(cofactor(matrix, 0, 2), -46.0f);
    ASSERT_EQ(determinant(matrix), -196.0f);
}

TEST(Matrix_test, 4x4_matrix_determinant) {
    Matrix matrix(
        -2.0f, -8.0f, 3.0f, 5.0f, 
        -3.0f, 1.0f, 7.0f, 3.0f,
        1.0f, 2.0f, -9.0f, 6.0f,
        -6.0f, 7.0f, 7.0f, -9.0f
    );

    ASSERT_EQ(cofactor(matrix, 0, 0), 690.0f);
    ASSERT_EQ(cofactor(matrix, 0, 1), 447.0f);
    ASSERT_EQ(cofactor(matrix, 0, 2), 210.0f);
    ASSERT_EQ(cofactor(matrix, 0, 3), 51.0f);
    ASSERT_EQ(determinant(matrix), -4071.0f);
}

TEST(Matrix_test, check_matrix_is_invertible_when_det_is_not_zero) {
    Matrix matrix(
        -2.0f, -8.0f, 3.0f, 5.0f, 
        -3.0f, 1.0f, 7.0f, 3.0f,
        1.0f, 2.0f, -9.0f, 6.0f,
        -6.0f, 7.0f, 7.0f, -9.0f
    );

    ASSERT_EQ(determinant(matrix), -4071.0f);
    ASSERT_TRUE(isInvertible(matrix));
}

TEST(Matrix_test, check_matrix_is_not_invertible_when_det_is_zero) {
    Matrix matrix(
        -4.0f, 2.0f, -2.0f, -3.0f, 
        9.0f, 6.0f, 2.0f, 6.0f,
        0.0f, -5.0f, 1.0f, -5.0f,
        0.0f, 0.0f, 0.0f, 0.0f
    );

    ASSERT_EQ(determinant(matrix), 0.0f);
    ASSERT_FALSE(isInvertible(matrix));
}


TEST(Matrix_test, calculate_the_inverse_of_a_matrix) {
    Matrix matrix(
        -5.0f, 2.0f, 6.0f, -8.0f, 
        1.0f, -5.0f, 1.0f, 8.0f,
        7.0f, 7.0f, -6.0f, -7.0f,
        1.0f, -3.0f, 7.0f, 4.0f
    );

    Matrix inv = inverse(matrix);

    Matrix result(
         0.21805f, 0.45113f, 0.24060f, -0.04511f,
        -0.80827f, -1.45677f, -0.44361f, 0.52068f,
        -0.07895f, -0.22368f, -0.05263f, 0.19737f,
        -0.52256f, -0.81391f, -0.30075f, 0.30639f
    );

    ASSERT_EQ(determinant(matrix), 532.0f);
    ASSERT_EQ(cofactor(matrix, 2, 3), -160.0f);
    ASSERT_TRUE(inv(3, 2) - (-160.0f/532.0f) < 0.0001);
    ASSERT_EQ(cofactor(matrix, 3, 2), 105.0f);
    ASSERT_TRUE(inv(2, 3) - (105.0f/532.0f) < 0.0001);
}

TEST(Matrix_test, multiply_a_product_by_its_inverse) {
    Matrix A(
        3.0f, -9.0f, 7.0f, 3.0f, 
        3.0f, -8.0f, 2.0f, -9.0f,
        -4.0f, 4.0f, 4.0f, 1.0f,
        -6.0f, 5.0f, -1.0f, 1.0f
    );

    Matrix B(
        8.0f, 2.0f, 2.0f, 2.0f, 
        3.0f, -1.0f, 7.0f, 0.0f,
        7.0f, 0.0f, 5.0f, 4.0f,
        6.0f, -2.0f, 0.0f, 5.0f
    );

    Matrix C = A * B;

    ASSERT_TRUE(C*inverse(B) == A);    
}
