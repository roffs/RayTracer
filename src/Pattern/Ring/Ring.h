#pragma once

#include "Pattern.h"
#include "Color.h"

class Ring : public Pattern {
public:
    Pattern* patternA;
    Pattern* patternB;
    
    Ring(Color a, Color b);
    Ring(Pattern &a, Pattern &b);
    Color colorAt(Tuple const &point) override;
};