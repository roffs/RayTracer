#include "Plane.h"

#include <cmath>

#include "Ray.h"
#include "Intersection.h"

std::vector<Intersection> Plane::localIntersects(Ray const &ray) {
    std::vector<Intersection> intersections;

    if (ray.direction.y > EPSILON || ray.direction.y < -EPSILON) {
        float t = - ray.origin.y / ray.direction.y;
        if (t > 0) {
            Intersection i(*this, t);
            intersections.push_back(i);
        }
    }
    return intersections;
};

Tuple Plane::localNormalAt(Tuple const &point) {
    return Tuple::Vector(0.0f, 1.0f, 0.0f);
}; 

