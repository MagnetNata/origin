#pragma once
#include <iostream>
#include "Parallelogramm1.h"

class Pryamougolnik : public Parallelogramm
{
protected:
    double a, b, c, d;
    int A, B, C, D;
public:
    Pryamougolnik(double a, double b, std::string name);

    void proverka() override;
};