#pragma once

#include "Surface.h"
#include "Tuple.h"
#include "Matrix.h"

class Sphere : public Surface {
public: 
    Tuple center;
    float radius;
    Matrix transform;

    Sphere();

    void setTransformation(Matrix transform);
    Tuple normal(Tuple point);
};