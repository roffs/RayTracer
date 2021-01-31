#include "Grid.h"
#include <math.h>

#include "Solid.h"

Grid::Grid(Color a, Color b) {
    patternA = new Solid(a); 
    patternB = new Solid(b); 
};

Grid::Grid(Pattern &a, Pattern &b) {
    patternA = &a; 
    patternB = &b; 
};


Color Grid::colorAt(Tuple const &point) {
    Tuple pointPatternSpaceA = inverse(patternA->transform) * point;
    Tuple pointPatternSpaceB = inverse(patternB->transform) * point;

    return ((int) (floor(point.x) + floor(point.y) + floor(point.z)) % 2) == 0 ? patternA->colorAt(pointPatternSpaceA) : patternB->colorAt(pointPatternSpaceB);
};