#include "Object.h"
#include "Ray.h"

int Object::currentId = 0;

Object::Object(){
    currentId++;
    id = currentId;

    transform = Matrix::Identity(4);
    material = Material();
}

bool Object::operator==(Object const& other){
    return id == other.id;
};

void Object::operator=(Object const& other) {
    (*this) = other; 
};

void Object::setTransformation(Matrix const &newTransform) {
    transform = newTransform;
};

std::vector<Intersection> Object::intersects(Ray const &ray) {
    Ray localRay = transformRay(ray, inverse(transform));
    return localIntersects(localRay);
};

Tuple Object::normalAt(Tuple const &point) {
    Tuple localPoint = inverse(transform) * point;
    Tuple localNormal = this->localNormalAt(localPoint);
    Tuple worldNormal = transpose(inverse(transform)) * localNormal;
    worldNormal.w = 0;

    return normalize(worldNormal);
};  