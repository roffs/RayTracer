#pragma once

#include <vector>

#include "Object.h"
#include "Light.h"

class World {
public: 
    std::vector<Object*> objects;
    std::vector<Light*> lights;

    World();
};


World defaultWorld();