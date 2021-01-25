#pragma once

#include "Matrix.h"
#include "Material.h"

class Surface {
public:
    int id;
    static int currentId; 

    Matrix transform;
    Material material;
    
    Surface();

    //operator overload
    bool operator==(Surface const& other);
    void operator=(Surface const& other);

    void setTransformation(Matrix const &transform);

    //virtual methods
    virtual Tuple normal(Tuple const &point) = 0;
};