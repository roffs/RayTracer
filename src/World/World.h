#pragma once

#include <vector>

#include "Object.h"
#include "Light.h"
#include "Intersection.h"
#include "Ray.h"
#include "Computation.h"


class World {
public: 
    std::vector<Object*> objects;
    Light light;

    World();

    static World DefaultWorld();

    bool isShadow(Tuple point) const;
};


//out of class

std::vector<Intersection> intersectsWorld(Ray const &ray, World const &world);

Color shadeHit(World const &world, Computation const &comp);

Color colorAt(World const &world, Ray const &ray);