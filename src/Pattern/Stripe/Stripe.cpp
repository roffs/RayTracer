#include "Stripe.h"
#include <cmath>

#include "Solid.h"

Stripe::Stripe(Color a, Color b) {
    patternA = new Solid(a); 
    patternB = new Solid(b); 
};

Stripe::Stripe(Pattern &a, Pattern &b) {
    patternA = &a; 
    patternB = &b; 
};

Color Stripe::colorAt(Tuple const &point) {
    Tuple pointPatternSpaceA = inverse(patternA->transform) * point;
    Tuple pointPatternSpaceB = inverse(patternB->transform) * point;

    Color color = ( (int)std::floor(point.x) % 2 == 0) ? patternA->colorAt(pointPatternSpaceA) : patternB->colorAt(pointPatternSpaceB);
    return color; 
};