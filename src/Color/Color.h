#pragma once

#include "Tuple.h"

class Color : public Tuple {
public:
    float &red = x;
    float &green = y;
    float &blue = z;

    Color(float x = 0.0f, float y = 0.0f, float z = 0.0f);
    Color(Color const &color);
    
    //Operator overloads
    bool operator== (Color const& other) const;
    void operator= (Color const& other);
    Color operator+ (Color const& other) const;
    Color operator- (Color const& other) const;
    Color operator* (float const& scalar) const;
    Color operator* (Color const& other) const;
};