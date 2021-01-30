#include <gtest/gtest.h>

#include "Ring.h"

class Ring_test: public ::testing::Test { 
public: 
    const Color black = Color(0.0f, 0.0f, 0.0f);
    const Color white = Color(1.0f, 1.0f, 1.0f);
};

TEST_F(Ring_test, ring_should_extend_in_both_x_and_z) {
    Ring ring(white, black);
    ASSERT_TRUE(ring.colorAt(Tuple::Point(0.0f, 0.0f, 0.0f)) == white);
    ASSERT_TRUE(ring.colorAt(Tuple::Point(1.0f, 0.0f, 0.0f)) == black);
    ASSERT_TRUE(ring.colorAt(Tuple::Point(0.0f, 0.0f, 1.0f)) == black);
    ASSERT_TRUE(ring.colorAt(Tuple::Point(0.708f, 0.0f, 0.708f)) == black);
}