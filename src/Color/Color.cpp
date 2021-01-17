#include "Color.h"
#include <iostream>

Color::Color(float x, float y, float z) : Tuple(x, y, z, 0) {};

Color Color::operator+ (Color const& other){
    return {x + other.x, y + other.y, z + other.z};
}

Color Color::operator- (Color const& other){
    return {x - other.x, y - other.y, z - other.z};
}

void Color::operator= (Color const& other){
    x = other.red;
    y = other.green;
    z = other.blue;
}

Color Color::operator* (float const& scalar){
    return {x*scalar, y*scalar, z*scalar};
}

Color Color::operator* (Color const& other) {
    return {x*other.x, y*other.y, z*other.z};
}

bool Color::operator== (Color const& other){
    return (x == other.x) && (y == other.y) && (z == other.z) && (w == other.w);
}