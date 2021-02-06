#pragma once

#include "Intersection.h"
#include "Ray.h"
#include "Tuple.h"

#include <vector>

class Computation {
public:
    float t;
    float n1, n2;
    Object* object;
    Tuple point;
    Tuple overPoint;
    Tuple underPoint; 
    Tuple eyeDirection;
    Tuple normal;
    Tuple reflectv;
    bool inside;

};


Computation prepareComputation(Intersection const &hit, Ray const &r, std::vector<Intersection> intersections);


static float* calculateN1andN2(Intersection const &hit, Ray const &r, std::vector<Intersection> intersections);