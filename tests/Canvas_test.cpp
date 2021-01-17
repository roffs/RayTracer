#include <gtest/gtest.h>
#include <iostream>

#include "Canvas.h"
#include "Color.h"

TEST(Canvas_test, constructor_creates_canvas_with_specified_width_and_height_of_white_pixels) {
    int width{10}, height{20};
    Canvas canvas{width, height};
    Color white{};

    ASSERT_EQ(canvas.width, width);
    ASSERT_EQ(canvas.height, height);
    ASSERT_TRUE(canvas.pixelAt(2, 4) == white);
}

TEST(Canvas_test, constructor_creates_canvas_with_height_times_width_white_pixels) {
    int width{10}, height{20};
    int x{4}, y{8};

    Color red{1.0f, 0.0f, 0.0f};
    Canvas canvas{width, height};    
    canvas.writePixel(x, y, red);

    ASSERT_TRUE(canvas.pixelAt(x, y) == red);
}