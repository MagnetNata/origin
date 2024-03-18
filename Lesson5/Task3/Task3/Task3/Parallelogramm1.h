#pragma once
#include <iostream>
#include "Chetirehugolnik1.h"

class Parallelogramm : public Chetirehugolnik
{
protected:
    double a, b, c, d;
    int A, B, C, D;
public:
    Parallelogramm(double a, double b, int A, int B);
    
    void proverka() override;
    
};