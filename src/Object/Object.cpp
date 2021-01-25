#include "Object.h"

int Object::currentId = 0;

Object::Object(){
    currentId++;
    id = currentId;
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