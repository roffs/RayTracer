#pragma once

#include "Tuple.h"

class Color : public Tuple {
public:
    float &red = x;
    float &green = y;
    float &blue = z;

    Color(float x = 0.0f, float y = 0.0f, float z = 0.0f);

    //Operator overloads
    bool operator== (Color const& other);
    void operator= (Color const& other);
    Color operator+ (Color const& other);
    Color operator- (Color const& other);
    Color operator* (float const& scalar);
    Color operator* (Color const& other);
};