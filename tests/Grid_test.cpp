#include <gtest/gtest.h>

#include "Grid.h"

class Grid_test: public ::testing::Test { 
public: 
    const Color black = Color(0.0f, 0.0f, 0.0f);
    const Color white = Color(1.0f, 1.0f, 1.0f);
};

TEST_F(Grid_test, grid_should_repeat_in_x) {
    Grid grid(white, black);
    ASSERT_TRUE(grid.colorAt(Tuple::Point(0.0f, 0.0f, 0.0f)) == white);
    ASSERT_TRUE(grid.colorAt(Tuple::Point(0.99f, 0.0f, 0.0f)) == white);
    ASSERT_TRUE(grid.colorAt(Tuple::Point(1.01f, 0.0f, 0.0f)) == black);
}

TEST_F(Grid_test, grid_should_repeat_in_y) {
    Grid grid(white, black);
    ASSERT_TRUE(grid.colorAt(Tuple::Point(0.0f, 0.0f, 0.0f)) == white);
    ASSERT_TRUE(grid.colorAt(Tuple::Point(0.0f, 0.99f, 0.0f)) == white);
    ASSERT_TRUE(grid.colorAt(Tuple::Point(0.0f, 1.01f, 0.0f)) == black);
}

TEST_F(Grid_test, grid_should_repeat_in_z) {
    Grid grid(white, black);
    ASSERT_TRUE(grid.colorAt(Tuple::Point(0.0f, 0.0f, 0.0f)) == white);
    ASSERT_TRUE(grid.colorAt(Tuple::Point(0.0f, 0.0f, 0.99f)) == white);
    ASSERT_TRUE(grid.colorAt(Tuple::Point(0.0f, 0.0f, 1.01f)) == black);
}