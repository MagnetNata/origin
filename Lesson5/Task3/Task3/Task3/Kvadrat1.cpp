#include <iostream>
#include "Pryamougolnik1.h"
#include "Kvadrat1.h"

Kvadrat::Kvadrat(double a) : Pryamougolnik(a, a)
    {
        kol_storon = 4;
        name = "Квадрат";
        this->a = a;
        this->b = a;
        this->c = a;
        this->d = a;
        this->A = 90;
        this->B = 90;
        this->C = 90;
        this->D = 90;
    }
    void Kvadrat::proverka()
    {
        if (A + B + C + D == 360 and a == b and b == c and c == d and A == B and B == C and C == D)
        {
            std::cout << "Правильная" << std::endl;
        }
        else
        {
            std::cout << "Неправильная" << std::endl;
        }
    }
