#pragma once

#include "Pattern.h"
#include "Color.h"

class Solid : public Pattern {
public:
    Color color;
    
    Solid(Color color);
    Color colorAt(Tuple const &point) override;
};