#pragma once
#include <iostream>
#include "Treugolnik1.h"

class Pramoug_Treugolnik : public Treugolnik
{
protected:
    double a, b, c;
    int A, B, C;
public:
    Pramoug_Treugolnik(double a, double b, double c, int A, int B);
    
    void proverka() override;
    
};