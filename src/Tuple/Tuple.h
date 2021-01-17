#pragma once

class Tuple {
public:
    float x, y, z, w;
    Tuple(float x, float y, float z, float w);

    //Factory methods
    static Tuple Point(float x, float y, float z);
    static Tuple Vector(float x, float y, float z);

    //Operator overloads
    bool operator== (Tuple const& other);
    Tuple operator+ (Tuple const& other);
    Tuple operator- (Tuple const& other);
    Tuple operator- ();
    Tuple operator* (float const& scalar);
    float operator* (Tuple const& other);
    Tuple operator/ (float const& scalar);

    bool isPoint();
    bool isVector();    
};

float magnitude(Tuple tuple);

Tuple normalize(Tuple tuple);

Tuple cross(Tuple tuple1, Tuple tuple2);
