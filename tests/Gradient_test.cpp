#include <gtest/gtest.h>

#include "Gradient.h"

class Gradient_test: public ::testing::Test { 
public: 
    const Color black = Color(0.0f, 0.0f, 0.0f);
    const Color white = Color(1.0f, 1.0f, 1.0f);
};

TEST_F(Gradient_test, gradient_linearly_interpolates_between_color) {
    Gradient gradient(white, black);
    ASSERT_TRUE(gradient.colorAt(Tuple::Point(0.0f, 0.0f, 0.0f)) == white);
    ASSERT_TRUE(gradient.colorAt(Tuple::Point(0.25f, 0.0f, 0.0f)) == Color(0.75f, 0.75f, 0.75f));
    ASSERT_TRUE(gradient.colorAt(Tuple::Point(0.5f, 0.0f, 0.0f)) == Color(0.5f, 0.5f, 0.5f));
    ASSERT_TRUE(gradient.colorAt(Tuple::Point(0.75f, 0.0f, 0.0f)) == Color(0.25f, 0.25f, 0.25f));
}