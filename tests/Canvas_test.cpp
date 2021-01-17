#include <gtest/gtest.h>
#include <sstream>
#include <string>
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
    ASSERT_TRUE(canvas.pixelAt(width-1, height-1) == white);
}

TEST(Canvas_test, constructor_creates_canvas_with_height_times_width_white_pixels) {
    int width{10}, height{20};
    int x{4}, y{8};

    Color red{1.0f, 0.0f, 0.0f};
    Canvas canvas{width, height};    
    canvas.writePixel(x, y, red);
    ASSERT_TRUE(canvas.pixelAt(x, y) == red);
}

TEST(Canvas_test, fill_updates_all_canvas_pixels_to_specified_color) {
    int width{10}, height{20};
    int x{4}, y{8};

    Color color{0.3f, 0.2f, 1.0f};
    Canvas canvas{width, height};    
    
    canvas.fill(color);
    ASSERT_TRUE(canvas.pixelAt(x, y) == color);
}

TEST(Canvas_test, canvasToPPM_creates_a_PPM_file_with_expected_header) {
    int width{10}, height{20};
    Canvas canvas{width, height};    

    std::stringstream ppm = canvasToPPM(canvas);
    std::string line;

    std::getline(ppm, line);
    ASSERT_EQ(line, "P3");

    std::getline(ppm, line);
    ASSERT_EQ(line, "10 20");

    std::getline(ppm, line);
    ASSERT_EQ(line, "255");
}

TEST(Canvas_test, canvasToPPM_creates_a_PPM_file_with_pixel_data) {
    int width{5}, height{3};
    Canvas canvas{width, height};
    
    Color color1(1.5f, 0.0f, 0.0f);
    Color color2(0.0f, 0.5f, 0.0f);
    Color color3(-0.5f, 0.0f, 1.0f);
    
    canvas.writePixel(0, 0, color1);
    canvas.writePixel(2, 1, color2);
    canvas.writePixel(4, 2, color3);

    std::stringstream ppm = canvasToPPM(canvas);
    std::string line;

    std::getline(ppm, line);
    std::getline(ppm, line);
    std::getline(ppm, line);

    std::getline(ppm, line);
    ASSERT_EQ(line, "255 0 0 0 0 0 0 0 0 0 0 0 0 0 0");
    std::getline(ppm, line);
    ASSERT_EQ(line, "0 0 0 0 0 0 0 128 0 0 0 0 0 0 0");
    std::getline(ppm, line);
    ASSERT_EQ(line, "0 0 0 0 0 0 0 0 0 0 0 0 0 0 255");
}

TEST(Canvas_test, PPM_lines_are_splitted_if_longer_than_70_characters) {
    int width{10}, height{2};
    Canvas canvas{width, height};
    Color color{1.0f, 0.8f, 0.6f};
    canvas.fill(color);

    std::stringstream ppm = canvasToPPM(canvas);
    std::string line;

    std::getline(ppm, line);
    std::getline(ppm, line);
    std::getline(ppm, line);

    std::getline(ppm, line);
    ASSERT_EQ(line, "255 204 153 255 204 153 255 204 153 255 204 153 255 204 153 255 204");
    std::getline(ppm, line);
    ASSERT_EQ(line, "153 255 204 153 255 204 153 255 204 153 255 204 153");
    std::getline(ppm, line);
    ASSERT_EQ(line, "255 204 153 255 204 153 255 204 153 255 204 153 255 204 153 255 204");
    std::getline(ppm, line);
    ASSERT_EQ(line, "153 255 204 153 255 204 153 255 204 153 255 204 153");

}
