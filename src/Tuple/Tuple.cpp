#include <cmath>

#include "Tuple.h"

Tuple::Tuple(float x, float y, float z, float w): x(x), y(y), z(z), w(w) {};

Tuple Tuple::Point(float x, float y, float z){
    return {x, y, z, 1.0f};
};

Tuple Tuple::Vector(float x, float y, float z){
    return {x, y, z, 0.0f};
};

bool Tuple::operator== (Tuple const& other){
    return (x == other.x) && (y == other.y) && (z == other.z) && (w == other.w);
}

bool Tuple::operator!= (Tuple const& other){
    return !(*this == other);
};

Tuple Tuple::operator+ (Tuple const& other){
    return {x + other.x, y + other.y, z + other.z, w + other.w};
}

Tuple Tuple::operator- (Tuple const& other){
    return {x - other.x, y - other.y, z - other.z, w - other.w};
}

Tuple Tuple::operator- (){
    return {-x, -y, -z, -w};
}

Tuple Tuple::operator* (float const& scalar){
    return {x*scalar, y*scalar, z*scalar, w*scalar};
}

float Tuple::operator* (Tuple const& other) {
    return x*other.x + y*other.y + z*other.z + w*other.w;
}

Tuple Tuple::operator/ (float const& scalar){
    return {x/scalar, y/scalar, z/scalar, w/scalar};
}

bool Tuple::isPoint() {
    return w==1.0f;
}

bool Tuple::isVector() {
    return w==0.0f;
}


//Out of class functions

float magnitude(Tuple tuple) {
    return sqrt(tuple.x*tuple.x + tuple.y*tuple.y + tuple.z*tuple.z + tuple.w*tuple.w);
}

Tuple normalize(Tuple tuple) {
    float mag = magnitude(tuple);
    return {tuple.x/mag, tuple.y/mag, tuple.z/mag, tuple.w/mag};
}

Tuple cross(Tuple tuple1, Tuple tuple2) {
    return Tuple::Vector(tuple1.y*tuple2.z - tuple1.z*tuple2.y, tuple1.x*tuple2.z - tuple1.z*tuple2.x, tuple1.x*tuple2.y - tuple1.y*tuple2.x);
}