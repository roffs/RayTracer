#pragma once

#include "Pattern.h"
#include "Color.h"

class Stripe : public Pattern {
public: 
    Pattern* patternA;
    Pattern* patternB;
    
    Stripe(Color a, Color b);
    Stripe(Pattern &a, Pattern &b);

    Color colorAt(Tuple const &point) override;
};