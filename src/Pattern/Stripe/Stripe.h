#pragma once

#include "Pattern.h"
#include "Color.h"

class Stripe : public Pattern {
public: 
    Color colorA;
    Color colorB;
    
    Stripe(Color a, Color b);
    Color colorAt(Tuple const &point) override;
};