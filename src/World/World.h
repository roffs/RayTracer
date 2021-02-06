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

    //void operator=(World const &other); //copy constructor
};


//out of class

std::vector<Intersection> intersectsWorld(Ray const &ray, World const &world);

Color shadeHit(World const &world, Computation const &comp, int remaining);

Color colorAt(World const &world, Ray const &ray, int remaining);

Color reflectedColor(World const &world, Computation const &comp, int remaining);

Color refractedColor(World const &world, Computation const &comp, int remaining);