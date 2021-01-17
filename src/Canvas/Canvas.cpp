#include "Canvas.h"

Canvas::Canvas(int width, int height) : width(width), height(height), arrayOfPixels(new Color[width*height]){
}

Color Canvas::pixelAt(int x, int y) {
    return arrayOfPixels[width*x + y];
}

void Canvas::writePixel(int x, int y, Color const& color){
    arrayOfPixels[width*x + y] = color;
};