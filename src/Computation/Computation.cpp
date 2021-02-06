#include "Computation.h"

#include <vector>
#include <algorithm>
#include <cmath>

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


float shlick(Computation const &comp) {
    float cos = comp.normal * comp.eyeDirection;

    if (comp.n1 > comp.n2) {
        float n = comp.n1 / comp.n2;
        float sin2_t = (n*n) * (1.0f - (cos*cos));

        if (sin2_t > 1.0f) {
            return 1.0f;
        }

        //when n1 > n2 use cos(theta_t) instead of cos
        cos = sqrt(1.0 - sin2_t);
    }

    float r0 = pow(((comp.n1 - comp.n2) / (comp.n1 + comp.n2)), 2.0f);
    return r0 + (1-r0)*pow((1-cos), 5.0f);
};