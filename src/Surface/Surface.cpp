#include "Surface.h"

int Surface::currentId = 0;

Surface::Surface(){
    currentId++;
    id = currentId;
}

bool Surface::operator==(Surface const& other){
    return id == other.id;
};

void Surface::operator=(Surface const& other) {
    (*this) = other; 
};

void Surface::setTransformation(Matrix const &newTransform) {
    transform = newTransform;
};