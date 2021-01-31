#include "Ring.h"
#include <cmath>

#include "Solid.h"

Ring::Ring(Color a, Color b) {
    patternA = new Solid(a); 
    patternB = new Solid(b); 
};

Ring::Ring(Pattern &a, Pattern &b) {
    patternA = &a; 
    patternB = &b; 
};



Color Ring::colorAt(Tuple const &point) {
    Tuple pointPatternSpaceA = inverse(patternA->transform) * point;
    Tuple pointPatternSpaceB = inverse(patternB->transform) * point;
    return (int) sqrt((point.x*point.x) + (point.z*point.z)) % 2 == 0 ? patternA->colorAt(pointPatternSpaceA) : patternB->colorAt(pointPatternSpaceB);
};