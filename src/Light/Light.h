#pragma once

#include "Color.h"
#include "Tuple.h"

class Light {
public:
    Tuple position;
    Color intensity;

    Light();
    Light(Tuple position, Color intensity);
};