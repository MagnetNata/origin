#pragma once
#include <iostream>
#include "Parallelogramm1.h"

class Romb : public Parallelogramm
{
protected:
    double a, b, c, d;
    int A, B, C, D;
public:
    Romb(double a, int A, int B);
   
    void proverka() override;
    
};