#pragma once

#include "Pattern.h"
#include "Color.h"

class Grid : public Pattern {
public:
    Color colorA;
    Color colorB;
    
    Grid(Color a, Color b);
    Color colorAt(Tuple const &point) override;
};