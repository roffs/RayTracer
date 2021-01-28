#include "Sphere.h"

#include <cmath>

#include "Ray.h" 

Sphere::Sphere() {
    center = Tuple::Point(0.0f, 0.0f, 0.0f);
    radius = 1.0f;
}


Tuple Sphere::localNormalAt(Tuple const &localPoint) {
    return localPoint - Tuple::Point(0.0f, 0.0f, 0.0f);
};

std::vector<Intersection> Sphere::localIntersects(Ray const &ray) {
    std::vector<Intersection> intersections;

    Tuple sphereToRay = ray.origin - center;

    float a = ray.direction * ray.direction;
    float b = 2 * (ray.direction * sphereToRay);
    float c = (sphereToRay*sphereToRay) - 1.0f;

    float det = (b*b) - (4*a*c);

    float t1, t2;
    if(det >= 0) {
        t1 = (-b - sqrt(det)) / (2*a);
        t2 = (-b + sqrt(det)) / (2*a);

        Intersection int1(*this, t1);
        Intersection int2(*this, t2);

        intersections.push_back(int1);
        intersections.push_back(int2);
    }    
    return intersections;
};