#include <iostream>
#include "Treugolnik1.h"
#include "Ravnobed_Treugolnik1.h"

Ravnobed_Treugolnik::Ravnobed_Treugolnik(double a, double b, int A, int B) : Treugolnik(a, b, a, A, B, A)
    {
        kol_storon = 3;
        name = "Равнобедренный треугольник";
        this->a = a;
        this->b = b;
        this->c = a;
        this->A = A;
        this->B = B;
        this->C = A;
    }
    void Ravnobed_Treugolnik::proverka()
    {
        if (A + B + C == 180 and a == c and A == C)
        {
            std::cout << "Правильная" << std::endl;
        }
        else
        {
            std::cout << "Неправильная" << std::endl;
        }
    }