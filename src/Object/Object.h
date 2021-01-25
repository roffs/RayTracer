#pragma once

#include "Matrix.h"
#include "Material.h"

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
};