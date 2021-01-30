#include "Material.h"
#include <cmath>

#include "Object.h"

Material::Material(Color const &color, float ambient, float diffuse, float specular, float shininess) :
     pattern(nullptr), color({color.red, color.green, color.blue}), ambient(ambient), diffuse(diffuse), specular(specular), shininess(shininess) {};


bool Material::operator== (Material const &other) {
    return  color == other.color &&
            ambient == other.ambient &&
            diffuse == other.diffuse &&
            specular == other.specular &&
            shininess == other.shininess;            
};

bool Material::operator!= (Material const &other){
    return !((*this) == other);
};

void Material::setPattern(Pattern &p) {
    pattern = &p;
};


//Out of class
Color lighting(Object* object, Light const &light, Tuple const &position, Tuple const &eyeDirection, Tuple const &normal, bool inShadow) {
    Material material = object->material;
    
    Color materialColor = (material.pattern == nullptr) ? material.color : object->colorAt(position);

    Color effectiveColor = materialColor * light.intensity;

    Tuple pointToLightSource = normalize(light.position - position);
    
    Color ambient = effectiveColor * material.ambient;

    float lightDotNormal = pointToLightSource * normal;

    Color diffuse, specular;
    if (lightDotNormal >= 0.0f) {
        diffuse = effectiveColor * (material.diffuse * lightDotNormal);
        Tuple reflectv = reflect(-pointToLightSource, normal);
        float reflectDotEye = reflectv * eyeDirection;
        if (reflectDotEye > 0.0f) {
            float factor = pow(reflectDotEye, material.shininess);
            specular = light.intensity * material.specular * factor;
        }
    } 

    Color result = ambient;
    
    if (!inShadow) {
        result = result + diffuse + specular;
    }

    return result; 
};