#pragma once
#include <iostream>
#include "Pryamougolnik1.h"

class Kvadrat : public Pryamougolnik
{
protected:
    double a, b, c, d;
    int A, B, C, D;
public:
    Kvadrat(double a);
   
    void proverka() override;
    
};