#include <gtest/gtest.h>

#include "Matrix.h"
#include "Tuple.h"

TEST(Matrix_test, constructor_creates_4x4_matrix_with_specified_values) {
    Matrix matrix(
        1.0f, 2.0f, 3.0f, 4.0f,
        5.5f, 6.5f, 7.5f, 8.5f,
        9.0f, 10.0f, 11.0f, 12.0f,
        13.5f, 14.5f, 15.5f, 16.5f
    );
    
    ASSERT_EQ(matrix(1, 1), 1.0f);
    ASSERT_EQ(matrix(1, 2), 2.0f);
    ASSERT_EQ(matrix(1, 3), 3.0f);
    ASSERT_EQ(matrix(1, 4), 4.0f);

    ASSERT_EQ(matrix(2, 1), 5.5f);
    ASSERT_EQ(matrix(2, 2), 6.5f);
    ASSERT_EQ(matrix(2, 3), 7.5f);
    ASSERT_EQ(matrix(2, 4), 8.5f);

    ASSERT_EQ(matrix(3, 1), 9.0f);
    ASSERT_EQ(matrix(3, 2), 10.0f);
    ASSERT_EQ(matrix(3, 3), 11.0f);
    ASSERT_EQ(matrix(3, 4), 12.0f);
    
    ASSERT_EQ(matrix(4, 1), 13.5f);
    ASSERT_EQ(matrix(4, 2), 14.5f);
    ASSERT_EQ(matrix(4, 3), 15.5f);
    ASSERT_EQ(matrix(4, 4), 16.5f);
}


TEST(Matrix_test, constructor_creates_3x3_matrix_with_specified_values) {
    Matrix matrix(
        -3.0f, 5.0f, 0.0f,
        1.0f, -2.0f, -7.0f,
        1.0f, 1.0f, 1.0f
    );
    
    ASSERT_EQ(matrix(1, 1), -3.0);
    ASSERT_EQ(matrix(1, 2), 5.0f);
    ASSERT_EQ(matrix(1, 3), 0.0f);

    ASSERT_EQ(matrix(2, 1), 1.0f);
    ASSERT_EQ(matrix(2, 2), -2.0f);
    ASSERT_EQ(matrix(2, 3), -7.0f);

    ASSERT_EQ(matrix(3, 1), 1.0f);
    ASSERT_EQ(matrix(3, 2), 1.0f);
    ASSERT_EQ(matrix(3, 3), 1.0f);
}

TEST(Matrix_test, constructor_creates_2x2_matrix_with_specified_values) {
    Matrix matrix(-3.0f, 5.0f, 1.0f, -2.0f);
    
    ASSERT_EQ(matrix(1, 1), -3.0f);
    ASSERT_EQ(matrix(1, 2), 5.0f);

    ASSERT_EQ(matrix(2, 1), 1.0);
    ASSERT_EQ(matrix(2, 2), -2.0f);
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

    ASSERT_EQ(result(1, 1), 20.0f);
    ASSERT_EQ(result(1, 2), 22.0f);
    ASSERT_EQ(result(1, 3), 50.0f);
    ASSERT_EQ(result(1, 4), 48.0f);

    ASSERT_EQ(result(2, 1), 44.0f);
    ASSERT_EQ(result(2, 2), 54.0f);
    ASSERT_EQ(result(2, 3), 114.0f);
    ASSERT_EQ(result(2, 4), 108.0f);

    ASSERT_EQ(result(3, 1), 40.0f);
    ASSERT_EQ(result(3, 2), 58.0f);
    ASSERT_EQ(result(3, 3), 110.0f);
    ASSERT_EQ(result(3, 4), 102.0f);

    ASSERT_EQ(result(4, 1), 16.0f);
    ASSERT_EQ(result(4, 2), 26.0f);
    ASSERT_EQ(result(4, 3), 46.0f);
    ASSERT_EQ(result(4, 4), 42.0f);
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