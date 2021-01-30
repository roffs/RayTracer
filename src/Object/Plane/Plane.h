#pragma once

#include <vector>

#include "Object.h"
#include "Tuple.h"

#include "Intersection.h"

class Plane : public Object {
public:
    
    std::vector<Intersection> localIntersects(Ray const &ray) override;
    Tuple localNormalAt(Tuple const &point) override; 
};