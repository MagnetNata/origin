#include <iostream>
#include "Treugolnik1.h"
#include "Ravnostor_Treugolnik1.h"


Ravnostor_Treugolnik::Ravnostor_Treugolnik(double a) : Treugolnik(a, a, a, 60, 60, 60)
    {
        kol_storon = 3;
        name = "Равносторонний треугольник";
        this->a = a;
        this->b = a;
        this->c = a;
        this->A = 60;
        this->B = 60;
        this->C = 60;
    }
void Ravnostor_Treugolnik::proverka()
    {
        if (A + B + C == 180 and a == b and b == c and A == B and B == C)
        {
            std::cout << "Правильная" << std::endl;
        }
        else
        {
            std::cout << "Неправильная" << std::endl;
        }
    }
