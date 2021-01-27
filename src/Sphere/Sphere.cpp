#include "Sphere.h"

#include <cmath>

#include "Ray.h" 

Sphere::Sphere() {
    center = Tuple::Point(0.0f, 0.0f, 0.0f);
    radius = 1.0f;
    transform = Matrix::Identity(4);
}


Tuple Sphere::normal(Tuple const &worldPoint) {
    Tuple objectPoint = inverse(transform) * worldPoint;
    Tuple objectOrigin = Tuple::Point(0.0f, 0.0f, 0.0f);

    Tuple objectNormal = objectPoint - objectOrigin;
    Tuple worldNormal = transpose(inverse(transform)) * objectNormal;
    
    worldNormal.w = 0;

    return normalize(worldNormal);
};

std::vector<Intersection> Sphere::intersects(Ray const &originalRay) {
    std::vector<Intersection> intersections;

    Ray ray = transformRay(originalRay, inverse(transform));
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