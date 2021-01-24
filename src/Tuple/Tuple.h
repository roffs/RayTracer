#pragma once

class Tuple {
public:
    float x, y, z, w;
    Tuple(float x, float y, float z, float w);
    Tuple();
    
    //Factory methods
    static Tuple Point(float x, float y, float z);
    static Tuple Vector(float x, float y, float z);

    //Operator overloads
    bool operator== (Tuple const& other) const;
    bool operator!= (Tuple const& other) const;
    Tuple operator+ (Tuple const& other) const;
    Tuple operator- (Tuple const& other) const;
    Tuple operator- () const;
    Tuple operator* (float const& scalar) const;
    float operator* (Tuple const& other) const;
    Tuple operator/ (float const& scalar) const;

    bool isPoint();
    bool isVector();    
};

float magnitude(Tuple const &tuple);

Tuple normalize(Tuple const &tuple);

Tuple cross(Tuple const &tuple1, Tuple const &tuple2);

Tuple reflect(Tuple const &in, Tuple const &normal);