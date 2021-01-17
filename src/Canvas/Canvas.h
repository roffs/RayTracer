#pragma once

#include <sstream>

#include "Color.h"

class Canvas {
public:
    int width, height;
    Color* arrayOfPixels;

    Canvas(int width, int height);

    Color pixelAt(int x, int y);

    void writePixel(int x, int y, Color const& color);
    void fill(Color const& color);
};

std::stringstream canvasToPPM(Canvas &canvas);

static void writeHeader(std::stringstream &ss, int width, int height);

static void writeBody(std::stringstream &ss, Canvas &canvas);

int clamp(float number);