#pragma once
#include <iostream>
#include "Treugolnik1.h"

class Ravnostor_Treugolnik : public Treugolnik
{
protected:
    double a, b, c;
    int A, B, C;
public:
    Ravnostor_Treugolnik(double a);

    void proverka() override;
    
};