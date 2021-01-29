#include "Color.h"
#include <iostream>
#include <cmath>

Color::Color(float x, float y, float z) : Tuple(x, y, z, 0) {};

Color::Color(Color const &color) {
    x = color.x; 
    y = color.y, 
    z = color.z;
};

Color Color::operator+ (Color const& other) const {
    return {x + other.x, y + other.y, z + other.z};
}

Color Color::operator- (Color const& other) const {
    return {x - other.x, y - other.y, z - other.z};
}

void Color::operator= (Color const& other) {
    x = other.x;
    y = other.y;
    z = other.z;
}

Color Color::operator* (float const& scalar) const {
    return {x*scalar, y*scalar, z*scalar};
}

Color Color::operator* (Color const& other) const {
    return {x*other.x, y*other.y, z*other.z};
}

bool Color::operator== (Color const& other) const {
    return  ((red - other.red) < EPSILON && (red - other.red) > -EPSILON) && 
            ((green - other.green) < EPSILON && (green - other.green) > -EPSILON) && 
            ((blue - other.blue) < EPSILON && (blue - other.blue) > -EPSILON);
}

