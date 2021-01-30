#include <gtest/gtest.h>

#include "Solid.h"
#include "Color.h"

TEST(Solid_test, solid_pattern_returns_same_color_in_all_points) {
    Color color(0.8f, 0.8f, 0.8f);
    Solid solid(color);

    ASSERT_TRUE(solid.colorAt(Tuple::Point(0.0f, 0.0f, 0.0f)) == color);
    ASSERT_TRUE(solid.colorAt(Tuple::Point(10.0f, 5.5f, -8.0f)) == color);
}