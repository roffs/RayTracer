#include "Intersection.h"

#include <cstdarg>
#include <limits>

Intersection::Intersection(Sphere const &sphere, float const &t) : sphere(sphere), t(t) {};

Intersection::Intersection() {};

bool Intersection::operator==(Intersection const& other) {
    return (sphere == other.sphere) && (t == other.t);
};


//out of class

Intersection hit(std::vector<Intersection> intersections) {
    Intersection current(intersections[0].sphere, std::numeric_limits<float>::infinity());
    
    for(std::vector<Intersection>::size_type i = 0; i != intersections.size(); i++) {
        if (intersections[i].t < current.t && intersections[i].t > 0.0f) {
            current = intersections[i];
        }
    }
    return current;
};