#include "Grid.h"
#include <math.h>

Grid::Grid(Color a, Color b) {
    colorA = a; 
    colorB = b; 
};

Color Grid::colorAt(Tuple const &point) {
    return ((int) (floor(point.x) + floor(point.y) + floor(point.z)) % 2) == 0 ? colorA : colorB;
};