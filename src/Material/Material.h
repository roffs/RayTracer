#pragma once

#include "Color.h"
#include "Light.h"
#include "Pattern.h"

class Object;

class Material {
public:
    Color color;
    float ambient;
    float diffuse;
    float specular;
    float shininess;
    float reflective;
    float transparency;
    float refractive_index;
    Pattern* pattern;

    Material(
        Color const &color = {1.0f, 1.0f, 1.0f}, 
        float ambient = 0.1f, 
        float diffuse = 0.9f, 
        float specular = 0.9f, 
        float shininess = 200.0f, 
        float reflective = 0.0f,
        float transparency = 0.0f,
        float refractive_index = 1.0f);

    //Operators overload
    bool operator== (Material const &other);
    bool operator!= (Material const &other);

    void setPattern(Pattern &p);
};


//Out of class
Color lighting(Object* object, Light const &light, Tuple const &position, Tuple const &eyeDirection, Tuple const &normal, bool inShadow);