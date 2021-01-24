#pragma once

#include "Matrix.h"
#include "Material.h"

class Surface {
public:
    int id;
    static int currentId; 
    Surface();

    bool operator==(Surface const& other);
};