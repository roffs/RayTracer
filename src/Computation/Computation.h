#pragma once

#include "Intersection.h"
#include "Ray.h"
#include "Tuple.h"

class Computation {
public:
    float t;
    Object* object;
    Tuple point;
    Tuple overPoint;
    Tuple eyeDirection;
    Tuple normal;
    Tuple reflectv;
    bool inside;
};


Computation prepareComputation(Intersection const &i, Ray const &r);