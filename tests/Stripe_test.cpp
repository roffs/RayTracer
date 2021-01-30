#include <gtest/gtest.h>

#include "Stripe.h"
#include "Color.h"
#include "Tuple.h"
#include "Sphere.h"
#include "Transformations.h"

class Stripe_test: public ::testing::Test { 
public: 
    const Color black = Color(0.0f, 0.0f, 0.0f);
    const Color white = Color(1.0f, 1.0f, 1.0f);
};

TEST_F(Stripe_test, stripe_pattern_is_constant_in_y) {
    Stripe stripe(white, black);

    ASSERT_TRUE(stripe.colorAt(Tuple::Point(0.0f, 0.0f, 0.0f)) == white);
    ASSERT_TRUE(stripe.colorAt(Tuple::Point(0.0f, 1.0f, 0.0f)) == white);
    ASSERT_TRUE(stripe.colorAt(Tuple::Point(0.0f, 2.0f, 0.0f)) == white);
}

TEST_F(Stripe_test, stripe_pattern_is_constant_in_z) {
    Stripe stripe(white, black);

    ASSERT_TRUE(stripe.colorAt(Tuple::Point(0.0f, 0.0f, 0.0f)) == white);
    ASSERT_TRUE(stripe.colorAt(Tuple::Point(0.0f, 0.0f, 1.0f)) == white);
    ASSERT_TRUE(stripe.colorAt(Tuple::Point(0.0f, 1.0f, 2.0f)) == white);
}

TEST_F(Stripe_test, stripe_pattern_alternates_in_x) {
    Stripe stripe(white, black);

    ASSERT_TRUE(stripe.colorAt(Tuple::Point(0.0f, 0.0f, 0.0f)) == white);
    ASSERT_TRUE(stripe.colorAt(Tuple::Point(0.9f, 0.0f, 0.0f)) == white);
    ASSERT_TRUE(stripe.colorAt(Tuple::Point(1.0f, 0.0f, 0.0f)) == black);
    ASSERT_TRUE(stripe.colorAt(Tuple::Point(-0.1f, 0.0f, 0.0f)) == black);
    ASSERT_TRUE(stripe.colorAt(Tuple::Point(-1.0f, 0.0f, 0.0f)) == black);
    ASSERT_TRUE(stripe.colorAt(Tuple::Point(-1.1f, 0.0f, 0.0f)) == white);
}
