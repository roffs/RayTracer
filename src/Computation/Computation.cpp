#include "Computation.h"

#include <vector>
#include <algorithm>

Computation prepareComputation(Intersection const &hit, Ray const &r,  std::vector<Intersection> intersections) {
    Computation comp; 

    comp.t = hit.t; 
    comp.object = hit.object;

    comp.point = position(r, hit.t);
    comp.eyeDirection = -r.direction;
    comp.normal = hit.object->normalAt(comp.point);
    comp.reflectv = reflect(r.direction, comp.normal);

    float* n = calculateN1andN2(hit, r, intersections);
    comp.n1 = n[0];
    comp.n2 = n[1];

    if(comp.normal * comp.eyeDirection < 0) {
        comp.inside = true;
        comp.normal = -comp.normal;
    }
    else {
        comp.inside = false; 
    }

    comp.overPoint = comp.point + comp.normal * EPSILON;
    comp.underPoint = comp.point - comp.normal * EPSILON;

    return comp; 
};

float* calculateN1andN2(Intersection const &hit, Ray const &r, std::vector<Intersection> intersections) {
    float n1, n2;
    std::vector<Object*> container;

    for(Intersection i : intersections) {
        if (i.t == hit.t) {
            if (container.empty()){
                n1 = 1.0f;
            } else {
                n1 = container.back()->material.refractive_index;
            }
        }

        if(std::find(container.begin(), container.end(), i.object) != container.end()) {
            container.erase(std::remove(container.begin(), container.end(), i.object), container.end());
        } else{
            container.push_back(i.object);
        }

        if (i.t == hit.t) {
            if (container.empty()){
                n2 = 1.0f;
            } else {
                n2 = container.back()->material.refractive_index;
            }
            break;
        }

    }
    
    float* ns = new float[2];
    ns[0] = n1;
    ns[1] = n2;
    return ns;
};