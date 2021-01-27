#include "Ray.h"
#include <limits>
#include <cmath>

Ray::Ray(Tuple const& origin, Tuple const& direction) : origin(origin), direction(direction) {};


//Outside of class
Tuple position(Ray const &ray, float t) {
    Tuple pos = ray.origin + (ray.direction*t);
    return pos;
};

Ray transformRay(Ray const& ray, Matrix const& transform) {
    return {transform * ray.origin, transform * ray.direction};
};