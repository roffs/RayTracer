#pragma once

#include <vector>

class Object; 

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