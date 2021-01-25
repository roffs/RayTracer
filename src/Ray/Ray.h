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

Tuple position(Ray &ray, float t);

std::vector<Intersection> intersects(Ray &ray, Sphere &sphere); 

Ray transform(Ray const& ray, Matrix const& transform);
