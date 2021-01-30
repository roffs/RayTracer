#pragma once

#include "Tuple.h"
#include "Color.h"
#include "Matrix.h"

class Pattern {
public:
    Matrix transform; 

    Pattern();
    virtual Color colorAt(Tuple const &point) = 0;
};