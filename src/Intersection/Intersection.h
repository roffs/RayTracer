#pragma once

#include <vector>

#include "Sphere.h"

class Intersection {
public:
    Sphere sphere;
    float t; 

    Intersection(Sphere const &sphere, float const &t);
    Intersection();

    bool operator==(Intersection const& other);
};

//out of class

Intersection hit(std::vector<Intersection> intersections);