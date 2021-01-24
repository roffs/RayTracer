#include "Sphere.h"

Sphere::Sphere() {
    center = Tuple::Point(0.0f, 0.0f, 0.0f);
    radius = 1.0f;
    transform = identity(4);
}

void Sphere::setTransformation(Matrix newTransform) {
    transform = newTransform;
};


Tuple Sphere::normal(Tuple worldPoint) {
    Tuple objectPoint = inverse(transform) * worldPoint;
    Tuple objectOrigin = Tuple::Point(0.0f, 0.0f, 0.0f);

    Tuple objectNormal = objectPoint - objectOrigin;
    Tuple worldNormal = transpose(inverse(transform)) * objectNormal;
    
    worldNormal.w = 0;

    return normalize(worldNormal);
};