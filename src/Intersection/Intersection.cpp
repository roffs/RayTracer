#include "Intersection.h"

#include <cstdarg>
#include <limits>

Intersection::Intersection(Object &object, float const &t) : object(&object), t(t) {};

Intersection::Intersection() : object(nullptr) {};


bool Intersection::operator==(Intersection const& other) {
    return (object == other.object) && (t == other.t);
};

void Intersection::operator= (Intersection const& other) {
    object = other.object; 
    t = other.t;
};


//out of class

Intersection hit(std::vector<Intersection> intersections) {
    Intersection current(*(intersections[0].object), std::numeric_limits<float>::infinity());
    
    for(std::vector<Intersection>::size_type i = 0; i != intersections.size(); i++) {
        if (intersections[i].t < current.t && intersections[i].t > 0.0f) {
            current = intersections[i];
        }
    }
    return current;
};