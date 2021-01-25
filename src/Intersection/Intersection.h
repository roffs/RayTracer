#pragma once

#include <vector>

#include "Object.h"

class Intersection {
public:
    Object *object;
    float t; 

    Intersection(Object &object, float const &t);
    Intersection();

    //operators overload
    bool operator== (Intersection const& other);
    void operator= (Intersection const& other);
};

//out of class

Intersection hit(std::vector<Intersection> intersections);