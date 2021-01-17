#include <gtest/gtest.h>
#include <iostream>

#include "Color.h"

class Color_test: public ::testing::Test { 
public: 
    const float red1{0.4f}, green1{0.5f}, blue1{0.7f};
    const float red2{0.2f}, green2{0.3f}, blue2{0.2f};
};

TEST_F(Color_test, color_is_constructed_from_rgb){
    Color color{red1, green1, blue1};

    ASSERT_EQ(color.red, red1);
    ASSERT_EQ(color.green, green1);
    ASSERT_EQ(color.blue, blue1);
}

TEST_F(Color_test, color_rgb_variables_are_references_to_xyz){
    Color color{red1, green1, blue1};

    color.x = 0.2f;
    ASSERT_EQ(color.red, 0.2f);
    ASSERT_EQ(color.x, 0.2f);
}

TEST_F(Color_test, adding_colors_returns_color_with_added_rgb){
    Color color1{red1, green1, blue1};
    Color color2{red2, green2, blue2};

    Color result = color1 + color2;
    ASSERT_EQ(result.red, red1+red2);
    ASSERT_EQ(result.green, green1+green2);
    ASSERT_EQ(result.blue, blue1+blue2);
}

TEST_F(Color_test, substracting_colors_returns_color_with_substracted_rgb){
    Color color1{red1, green1, blue1};
    Color color2{red2, green2, blue2};

    Color result = color1 - color2;
    ASSERT_EQ(result.red, red1-red2);
    ASSERT_EQ(result.green, green1-green2);
    ASSERT_EQ(result.blue, blue1-blue2);
}

TEST_F(Color_test, multiplying_color_by_scalar_returns_color_scalar_times_rgb){
    Color color{red1, green1, blue1};
    float scalar = 2.0f;
    color = color*scalar;

    ASSERT_EQ(color.red, red1*scalar);
    ASSERT_EQ(color.green, green1*scalar);
    ASSERT_EQ(color.blue, blue1*scalar);
}

TEST_F(Color_test, multiplying_color_by_color_returns_color_with_hadamard_product){
    Color color1{red1, green1, blue1};
    Color color2{red2, green2, blue2};

    Color result = color1 * color2;

    ASSERT_EQ(result.red, red1*red2);
    ASSERT_EQ(result.green, green1*green2);
    ASSERT_EQ(result.blue, blue1*blue2);
}