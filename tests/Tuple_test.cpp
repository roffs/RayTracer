#include <gtest/gtest.h>
#include <cmath>

#include "Tuple.h"

class Tuple_test: public ::testing::Test { 
public: 
    const float x1{1.0f}, y1{2.0f}, z1{3.0f};
    const float x2{2.0f}, y2{1.0f}, z2{0.0f};
    const float zero{0.0f}, one{1.0f};
};

TEST_F(Tuple_test, is_point_when_w_is_1) {
    Tuple tuple{x1, y1, z1, one};
    ASSERT_EQ(tuple.x, x1);
    ASSERT_EQ(tuple.y, y1);
    ASSERT_EQ(tuple.z, z1);
    ASSERT_EQ(tuple.w, one);
    ASSERT_TRUE(tuple.isPoint());
    ASSERT_FALSE(tuple.isVector());
}

TEST_F(Tuple_test, is_direction_when_w_is_0){
    Tuple tuple{x1, y1, z1, zero};
    
    ASSERT_EQ(tuple.x, x1);
    ASSERT_EQ(tuple.y, y1);
    ASSERT_EQ(tuple.z, z1);
    ASSERT_EQ(tuple.w, zero);
    ASSERT_FALSE(tuple.isPoint());
    ASSERT_TRUE(tuple.isVector());
}

TEST_F(Tuple_test, creates_point_with_point_factory_method){
    Tuple tuple = Tuple::Point(x1, y1, z1);
    
    ASSERT_EQ(tuple.x, x1);
    ASSERT_EQ(tuple.y, y1);
    ASSERT_EQ(tuple.z, z1);
    ASSERT_EQ(tuple.w, one);
}

TEST_F(Tuple_test, creates_vector_with_vector_factory_method){
    Tuple tuple = Tuple::Vector(x1, y1, z1);

    ASSERT_EQ(tuple.x, x1);
    ASSERT_EQ(tuple.y, y1);
    ASSERT_EQ(tuple.z, z1);
    ASSERT_EQ(tuple.w, zero);
}

TEST_F(Tuple_test, tuple_equal_operator_overload){
    float x{1.0f}, y{2.0f}, z{3.0f}, w{1.0f};
    Tuple tuple1(x1, y1, z1, one);
    Tuple tuple2(x1, y1, z1, one);
    Tuple tuple3(y1, x1, z1, one);

    ASSERT_TRUE(tuple1 == tuple2);
    ASSERT_FALSE(tuple1 == tuple3);
    ASSERT_FALSE(tuple1 != tuple2);
    ASSERT_TRUE(tuple1 != tuple3);
}

TEST_F(Tuple_test, point_plus_vector_gives_point){
    Tuple point = Tuple::Point(x1, y1, z1);
    Tuple vector = Tuple::Vector(x2, y2, z2);
    Tuple result = point + vector;

    ASSERT_EQ(result.x, x1 + x2);
    ASSERT_EQ(result.y, y1 + y2);
    ASSERT_EQ(result.z, z1 + z2);
    ASSERT_TRUE(result.isPoint());
}

TEST_F(Tuple_test, point_minus_point_gives_a_vector){
    Tuple point1 = Tuple::Point(x1, y1, z1);
    Tuple point2 = Tuple::Point(x2, y2, z2);
    Tuple result = point1 - point2;

    ASSERT_EQ(result.x, x1 - x2);
    ASSERT_EQ(result.y, y1 - y2);
    ASSERT_EQ(result.z, z1 - z2);
    ASSERT_TRUE(result.isVector());
}

TEST_F(Tuple_test, point_minus_vector_gives_a_point){
    Tuple point = Tuple::Point(x1, y1, z1);
    Tuple vector = Tuple::Vector(x2, y2, z2);
    Tuple result = point - vector;

    ASSERT_EQ(result.x, x1 - x2);
    ASSERT_EQ(result.y, y1 - y2);
    ASSERT_EQ(result.z, z1 - z2);
    ASSERT_TRUE(result.isPoint());
}

TEST_F(Tuple_test, vector_minus_vector_gives_a_vector){
    Tuple vector1 = Tuple::Vector(x1, y1, z1);
    Tuple vector2 = Tuple::Vector(x2, y2, z2);
    Tuple result = vector1 - vector2;

    ASSERT_EQ(result.x, x1 - x2);
    ASSERT_EQ(result.y, y1 - y2);
    ASSERT_EQ(result.z, z1 - z2);
    ASSERT_TRUE(result.isVector());
}

TEST_F(Tuple_test, tuple_negating_operator_overload){
    Tuple tuple{x1, y1, z1, one};

    Tuple result = -tuple;

    ASSERT_EQ(result.x, -x1);
    ASSERT_EQ(result.y, -y1);
    ASSERT_EQ(result.z, -z1);
    ASSERT_EQ(result.w, -one);
}

TEST_F(Tuple_test, tuple_multiplication_by_float_operator_overload){
    const float scalar = 3.0f;
    Tuple tuple{x1, y1, z1, one};
    Tuple result1 = tuple*scalar;
    
    ASSERT_EQ(result1.x, x1*scalar);
    ASSERT_EQ(result1.y, y1*scalar);
    ASSERT_EQ(result1.z, z1*scalar);
    ASSERT_EQ(result1.w, one*scalar);   
}

TEST_F(Tuple_test, tuple_multiplication_by_another_tuple_operator_is_dot_product_overload){
    Tuple tuple1{x1, y1, z1, one};
    Tuple tuple2{x2, y2, z2, one};
    float expected = x1*x2 + y1*y2 + z1*z2 + one*one;
    float result = tuple1 * tuple2;

    ASSERT_EQ(result, expected);   
}

TEST_F(Tuple_test, tuple_division_operator_overload){
    const float scalar = 3.0f;
    Tuple tuple{x1, y1, z1, one};
    Tuple result1 = tuple*scalar;
    
    ASSERT_EQ(result1.x, x1*scalar);
    ASSERT_EQ(result1.y, y1*scalar);
    ASSERT_EQ(result1.z, z1*scalar);
    ASSERT_EQ(result1.w, one*scalar);   
}

TEST_F(Tuple_test, magnitude_should_return_tuple_length){
    Tuple tuple{x1, y1, z1, one};
    float expected = sqrt(x1*x1 + y1*y1 + z1*z1 + one*one);
    float result = magnitude(tuple);

    ASSERT_EQ(result, expected);
}

TEST_F(Tuple_test, normalize_should_return_normalized_tuple){
    Tuple tuple{x1, y1, z1, one};
    float magnitude = sqrt(x1*x1 + y1*y1 + z1*z1 + one*one);
    Tuple expected = tuple / magnitude;
    Tuple result = normalize(tuple);

    ASSERT_TRUE(result == expected);
}

TEST_F(Tuple_test, cross_should_return_cross_product_of_vector){
    Tuple vector1 = Tuple::Vector(x1, y1, z1);
    Tuple vector2 = Tuple::Vector(x2, y2, z2);
    Tuple expected = Tuple::Vector(y1*z2 - z1*y2, z1*x2 - x1*z2, x1*y2 - y1*x2);
    Tuple result = cross(vector1, vector2);

    ASSERT_TRUE(result == expected);
}

TEST_F(Tuple_test, reflects_a_vector_approaching_at_45_deg) {
    Tuple v = Tuple::Vector(1.0f, -1.0f, 0.0f);
    Tuple n = Tuple::Vector(0.0f, 1.0f, 0.0f);

    Tuple r = reflect(v, n);

    Tuple expected = Tuple::Vector(1.0f, 1.0f, 0.0f);
    ASSERT_TRUE(r == expected);
}

TEST_F(Tuple_test, reflects_a_vector_off_a_slanted_object) {
    Tuple v = Tuple::Vector(0.0f, -1.0f, 0.0f);
    Tuple n = Tuple::Vector(sqrt(2.0f)/2.0f, sqrt(2.0f)/2.0f, 0.0f);

    Tuple r = reflect(v, n);

    Tuple expected = Tuple::Vector(1.0f, 0.0f, 0.0f);
    ASSERT_TRUE(r == expected);
}