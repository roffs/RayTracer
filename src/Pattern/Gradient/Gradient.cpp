#include "Gradient.h"
#include <cmath>

Gradient::Gradient(Color a, Color b) {
    colorA = a; 
    colorB = b; 
};

Color Gradient::colorAt(Tuple const &point) {
    Color distance = colorB - colorA;
    float fraction = point.x - floor(point.x);
    return colorA + distance*fraction;
};