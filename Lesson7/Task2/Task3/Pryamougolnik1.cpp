#include <iostream>
#include "Parallelogramm1.h"
#include "Pryamougolnik1.h"


Pryamougolnik::Pryamougolnik(double a, double b) : Parallelogramm(a, b, 90, 90)
    {
        kol_storon = 4;
        name = "Прямоугольник";
        this->a = a;
        this->b = b;
        this->c = a;
        this->d = b;
        this->A = 90;
        this->B = 90;
        this->C = 90;
        this->D = 90;
    }
    void Pryamougolnik::proverka()
    {
        if (A + B + C + D == 360 and a == c and b == d and A == B and B == C and C == D)
        {
            std::cout << "Правильная" << std::endl;
        }
        else
        {
            std::cout << "Неправильная" << std::endl;
        }
    }