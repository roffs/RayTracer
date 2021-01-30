#include "Grid.h"
#include <cmath>

Grid::Grid(Color a, Color b) {
    colorA = a; 
    colorB = b; 
};

Color Grid::colorAt(Tuple const &point) {
    float x = (point.x > 0) ? point.x : -point.x;
    float y = (point.y > 0) ? point.y : -point.y;
    float z = (point.z > 0) ? point.z : -point.z;

    return (int) (x + y + z) % 2 == 0 ? colorA : colorB;
};