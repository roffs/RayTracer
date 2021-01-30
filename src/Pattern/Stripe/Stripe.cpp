#include "Stripe.h"
#include <cmath>

Stripe::Stripe(Color a, Color b) {
    colorA = a; 
    colorB = b; 
};

Color Stripe::colorAt(Tuple const &point) {
    Color color = ( (int)std::floor(point.x) % 2 == 0) ? colorA : colorB;
    return color; 
};