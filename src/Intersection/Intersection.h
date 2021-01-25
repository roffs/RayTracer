#pragma once

#include <vector>

#include "Surface.h"

class Intersection {
public:
    Surface *surface;
    float t; 

    Intersection(Surface &surface, float const &t);
    Intersection();

    //operators overload
    bool operator== (Intersection const& other);
    void operator= (Intersection const& other);
};

//out of class

Intersection hit(std::vector<Intersection> intersections);