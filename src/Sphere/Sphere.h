#pragma once

#include "Surface.h"
#include "Tuple.h"
#include "Matrix.h"
#include "Material.h"

class Sphere : public Surface {
public: 
    Tuple center;
    float radius;
    Matrix transform;
    Material material;

    Sphere();

    void setTransformation(Matrix const &transform);
    Tuple normal(Tuple const &point);
};