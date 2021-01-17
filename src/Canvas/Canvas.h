#pragma once

#include "Color.h"

class Canvas {
public:
    int width, height;
    Color* arrayOfPixels;

    Canvas(int width, int height);

    Color pixelAt(int x, int y);

    void writePixel(int x, int y, Color const& color);
};