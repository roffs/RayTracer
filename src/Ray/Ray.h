#pragma once

#include "Tuple.h"
#include "Sphere.h"
#include "Intersection.h"
#include "Matrix.h"

class Ray {
public:
    Tuple origin;
    Tuple direction;
    Ray(Tuple const &origin, Tuple const &direction);   
};

Tuple position(Ray const &ray, float t);

Ray transformRay(Ray const& ray, Matrix const& transform);
