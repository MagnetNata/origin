#include <iostream>
#include "Parallelogramm1.h"
#include "Romb1.h"

Romb::Romb(double a, int A, int B) : Parallelogramm(a, a, A, B)
    {
        kol_storon = 4;
        name = "Ромб";
        this->a = a;
        this->b = a;
        this->c = a;
        this->d = a;
        this->A = A;
        this->B = B;
        this->C = A;
        this->D = B;
    }
    void Romb::proverka()
    {
        if (A + B + C + D == 360 and a == b and b == c and c == d and A == C and B == D)
        {
            std::cout << "Правильная" << std::endl;
        }
        else
        {
            std::cout << "Неправильная" << std::endl;
        }
    }