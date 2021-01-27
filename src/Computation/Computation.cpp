#include "Computation.h"



Computation prepareComputation(Intersection const &i, Ray const &r) {
    Computation comp; 

    comp.t = i.t; 
    comp.object = i.object;

    comp.point = position(r, i.t);
    comp.eyeDirection = -r.direction;
    comp.normal = i.object->normal(comp.point);

    if(comp.normal * comp.eyeDirection < 0) {
        comp.inside = true;
        comp.normal = -comp.normal;
    }
    else {
        comp.inside = false; 
    }

    return comp; 
};