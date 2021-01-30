#include "Ring.h"
#include <cmath>

Ring::Ring(Color a, Color b) {
    colorA = a; 
    colorB = b; 
};

Color Ring::colorAt(Tuple const &point) {
    return (int) sqrt((point.x*point.x) + (point.z*point.z)) % 2 == 0 ? colorA : colorB;
};