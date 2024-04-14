#pragma once
#include <iostream>
#include "Treugolnik1.h"

class Ravnobed_Treugolnik : public Treugolnik
{
protected:
    double a, b, c;
    int A, B, C;
public:
    Ravnobed_Treugolnik(double a, double b, int A, int B, std::string name);

    void proverka() override;
    
};