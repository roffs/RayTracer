#pragma once

#include "Object.h"
#include "Tuple.h"
#include "Matrix.h"
#include "Material.h"

class Sphere : public Object {
public: 
    Tuple center;
    float radius;

    Sphere();

    Tuple normal(Tuple const &point) override;
};