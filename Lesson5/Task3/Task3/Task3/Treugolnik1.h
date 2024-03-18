#pragma once
#include "Figura1.h"
class Treugolnik : public Figura
{
protected:
    double a, b, c;
    int A, B, C;
public:
    Treugolnik(double a, double b, double c, int A, int B, int C);
    void proverka() override;    
    double get_a();   
    double get_b();    
    double get_c();    
    int get_A();    
    int get_B();   
    int get_C();   
    void print_information() override;  
};