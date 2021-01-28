#pragma once

#include <vector>

#include "Object.h"
#include "Tuple.h"
#include "Matrix.h"
#include "Material.h"

#include "Intersection.h"

class Sphere : public Object {
public: 
    Tuple center;
    float radius;

    Sphere();

    Tuple localNormalAt(Tuple const &localPoint) override;
    std::vector<Intersection> localIntersects(Ray const &ray) override;
};