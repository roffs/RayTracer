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


//class for testing purposes
class TestPattern : public Pattern {
public:

    Color colorAt(Tuple const &point) override {
        return {point.x, point.y, point.z};
    };
};