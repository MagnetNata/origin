#include <iostream>
#include "Treugolnik1.h"
#include "Pramoug_Treugolnik1.h"


Pramoug_Treugolnik::Pramoug_Treugolnik(double a, double b, double c, int A, int B) : Treugolnik(a, b, c, A, B, 90)
    {
        kol_storon = 3;
        name = "Прямоугольный треугольник";
        this->a = a;
        this->b = b;
        this->c = c;
        this->A = A;
        this->B = B;
        this->C = 90;
    }
    void Pramoug_Treugolnik::proverka()
    {
        if (A + B + C == 180 and C == 90)
        {
            std::cout << "Правильная" << std::endl;
        }
        else
        {
            std::cout << "Неправильная" << std::endl;
        }
    }