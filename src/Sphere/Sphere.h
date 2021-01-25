#pragma once

#include "Surface.h"
#include "Tuple.h"
#include "Matrix.h"
#include "Material.h"

class Sphere : public Surface {
public: 
    Tuple center;
    float radius;

    Sphere();

    Tuple normal(Tuple const &point) override;
};