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
    Pattern* pattern = new TestPattern; 
    
    ASSERT_TRUE(pattern->transform == Matrix::Identity(4));
}


TEST_F(Pattern_test, pattern_with_an_object_transformation) {
    Sphere sphere;
    sphere.setTransformation(scaling(2.0f, 2.0f, 2.0f));

    Pattern* pattern = new TestPattern; 
    sphere.material.setPattern(*pattern);

    ASSERT_TRUE(sphere.colorAt(Tuple::Point(2.0f, 3.0f, 4.0f)) == Color(1.0f, 1.5f, 2.0f));
}

TEST_F(Pattern_test, pattern_with_a_pattern_transformation) {
    Sphere sphere;

    Pattern* pattern = new TestPattern; 
    pattern->transform = scaling(2.0f, 2.0f, 2.0f);

    sphere.material.setPattern(*pattern);

    ASSERT_TRUE(sphere.colorAt(Tuple::Point(2.0f, 3.0f, 4.0f)) == Color(1.0f, 1.5f, 2.0f));
}

TEST_F(Pattern_test, pattern_with_both_pattern_and_object_transformation) {
    Sphere sphere;
    sphere.setTransformation(scaling(2.0f, 2.0f, 2.0f));

    Pattern* pattern = new TestPattern; 
    pattern->transform= translation(0.5f, 1.0f, 1.5f);

    sphere.material.setPattern(*pattern);

    ASSERT_TRUE(sphere.colorAt(Tuple::Point(2.5f, 3.0f, 3.5f)) ==  Color(0.75f, 0.5f, 0.25f));
}