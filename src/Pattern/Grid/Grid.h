#pragma once

#include "Pattern.h"
#include "Color.h"

class Grid : public Pattern {
public:
    Pattern* patternA;
    Pattern* patternB;
    
    Grid(Color a, Color b);
    Grid(Pattern &a, Pattern &b);
    
    Color colorAt(Tuple const &point) override;
};