#include <gtest/gtest.h>

#include "Pattern.h"
#include "Stripe.h"
#include "Sphere.h"
#include "Transformations.h"

class Pattern_test: public ::testing::Test { 
public: 
    const Color black = Color(0.0f, 0.0f, 0.0f);
    const Color white = Color(1.0f, 1.0f, 1.0f);
};

TEST_F(Pattern_test, default_pattern_transformation_is_identity_matrix) {
    Stripe stripe(white, black);
    Pattern* pattern = &stripe; 
    
    ASSERT_TRUE(pattern->transform == Matrix::Identity(4));
}


TEST_F(Pattern_test, pattern_with_an_object_transformation) {
    Sphere sphere;
    sphere.setTransformation(scaling(2.0f, 2.0f, 2.0f));

    Stripe stripe(white, black);
    sphere.material.setPattern(stripe);

    ASSERT_TRUE(sphere.colorAt(Tuple::Point(1.5f, 0.0f, 0.0f)) == white);
}

TEST_F(Pattern_test, pattern__with_a_pattern_transformation) {
    Sphere sphere;

    Stripe stripe(white, black);
    stripe.transform = scaling(2.0f, 2.0f, 2.0f);

    sphere.material.setPattern(stripe);

    ASSERT_TRUE(sphere.colorAt(Tuple::Point(1.5f, 0.0f, 0.0f)) == white);
}

TEST_F(Pattern_test, pattern_with_both_pattern_and_object_transformation) {
    Sphere sphere;
    sphere.setTransformation(scaling(2.0f, 2.0f, 2.0f));

    Stripe stripe(white, black);
    stripe.transform = translation(0.5f, 0.0f, 0.0f);

    sphere.material.setPattern(stripe);

    ASSERT_TRUE(sphere.colorAt(Tuple::Point(2.5f, 0.0f, 0.0f)) == white);
}