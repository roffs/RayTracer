#pragma once

#include "Color.h"
#include "Tuple.h"

class Light {
public:
    Tuple position;
    Color intensity;

    Light(Tuple position, Color intensity);
};