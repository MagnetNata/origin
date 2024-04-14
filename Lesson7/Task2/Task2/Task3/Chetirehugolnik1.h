#pragma once
#include <iostream>
#include "Figura1.h"

class Chetirehugolnik : public Figura
{
protected:
    double a, b, c, d;
    int A, B, C, D;
public:
    Chetirehugolnik(double a, double b, double c, double d, int A, int B, int C, int D, std::string name);
    void proverka() override;
    
    double get_a();
    
    double get_b();
    
    double get_c();
    
    double get_d();
    
    int get_A();
    
    int get_B();
    
    int get_C();
    
    int get_D();
    
    void print_information() override;
};