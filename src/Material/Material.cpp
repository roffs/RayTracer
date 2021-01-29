#include "Material.h"
#include <cmath>

Material::Material(Color const &color, float ambient, float diffuse, float specular, float shininess) :
    color({color.red, color.green, color.blue}), ambient(ambient), diffuse(diffuse), specular(specular), shininess(shininess) {};


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


//Out of class
Color lighting(Material const &material, Light const &light, Tuple const &position, Tuple const &eyeDirection, Tuple const &normal, bool inShadow) {
    Color effectiveColor = material.color * light.intensity;

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