#include "Intersection.h"

#include <cstdarg>
#include <limits>

Intersection::Intersection(Surface surface, float t) : surface(surface), t(t) {};

Intersection::Intersection() {};

bool Intersection::operator==(Intersection const& other) {
    return (surface == other.surface) && (t == other.t);
};


//out of class

Intersection hit(std::vector<Intersection> intersections) {
    Intersection current(intersections[0].surface, std::numeric_limits<float>::infinity());
    
    for(std::vector<Intersection>::size_type i = 0; i != intersections.size(); i++) {
        if (intersections[i].t < current.t && intersections[i].t > 0.0f) {
            current = intersections[i];
        }
    }
    return current;
};