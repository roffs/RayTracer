#pragma once

#include "Color.h"
#include "Light.h"

class Material {
public:
    Color color;
    float ambient;
    float diffuse;
    float specular;
    float shininess;

    Material(Color const &color = {1.0f, 1.0f, 1.0f}, float ambient = 0.1f, float diffuse = 0.9f, float specular = 0.9f, float shininess = 200.0f);

    //Operators overload
    bool operator== (Material const &other);
    bool operator!= (Material const &other);
};


//Out of class
Color lighting(Material const &material, Light const &light, Tuple const &position, Tuple const &eyeDirection, Tuple const &normal, bool inShadow);