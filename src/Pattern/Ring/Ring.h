#pragma once

#include "Pattern.h"
#include "Color.h"

class Ring : public Pattern {
public:
    Color colorA;
    Color colorB;
    
    Ring(Color a, Color b);
    Color colorAt(Tuple const &point) override;
};