#pragma once

#include "Object.h"

class Cube : public Object {
public: 
    Tuple localNormalAt(Tuple const &localPoint) override;
    std::vector<Intersection> localIntersects(Ray const &ray) override;
};

float* check_axis(float origin, float direction);