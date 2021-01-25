#include "Ray.h"
#include <limits>
#include <cmath>

Ray::Ray(Tuple const& origin, Tuple const& direction) : origin(origin), direction(direction) {};


//Outside of class
Tuple position(Ray &ray, float t) {
    Tuple pos = ray.origin + (ray.direction*t);
    return pos;
};

std::vector<Intersection> intersects(Ray &originalRay, Sphere &sphere) {
    std::vector<Intersection> intersections;

    Ray ray = transform(originalRay, inverse(sphere.transform));
    Tuple sphereToRay = ray.origin - sphere.center;

    float a = ray.direction * ray.direction;
    float b = 2 * (ray.direction * sphereToRay);
    float c = (sphereToRay*sphereToRay) - 1.0f;

    float det = (b*b) - (4*a*c);

    float t1, t2;
    if(det >= 0) {
        t1 = (-b - sqrt(det)) / (2*a);
        t2 = (-b + sqrt(det)) / (2*a);

        Intersection int1(sphere, t1);
        Intersection int2(sphere, t2);

        intersections.push_back(int1);
        intersections.push_back(int2);

    }    
    return intersections;
}; 


Ray transform(Ray const& ray, Matrix const& transform) {
    return {transform * ray.origin, transform * ray.direction};
};