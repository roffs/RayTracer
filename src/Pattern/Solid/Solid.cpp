#include "Solid.h"
#include <cmath>

Solid::Solid(Color a) {
    color = a; 
};

Color Solid::colorAt(Tuple const &point) {
    return color; 
};