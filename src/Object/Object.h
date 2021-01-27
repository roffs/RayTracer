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

    //virtual methods
    virtual Tuple normal(Tuple const &point) = 0;
    virtual std::vector<Intersection> intersects(Ray const &originalRay) = 0;
};