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

    Tuple normal(Tuple const &point) override;
    std::vector<Intersection> intersects(Ray const &originalRay) override;
};