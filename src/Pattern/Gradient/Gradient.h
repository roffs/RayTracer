#pragma once

#include "Pattern.h"
#include "Color.h"

class Gradient : public Pattern {
public:
    Color colorA;
    Color colorB;
    
    Gradient(Color a, Color b);
    Color colorAt(Tuple const &point) override;
};