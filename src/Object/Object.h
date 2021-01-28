#pragma once

#include <vector>

#include "Matrix.h"
#include "Material.h"

class Intersection;
class Ray;

class Object {
public:
    int id;
    static int currentId; 

    Matrix transform;
    Material material;
    
    Object();

    //operator overload
    bool operator==(Object const& other);
    void operator=(Object const& other);

    void setTransformation(Matrix const &transform);
    std::vector<Intersection> intersects(Ray const &ray);
    Tuple normalAt(Tuple const &point);  

    //virtual methods
    virtual std::vector<Intersection> localIntersects(Ray const &ray) = 0;
    virtual Tuple localNormalAt(Tuple const &point) = 0;    
};