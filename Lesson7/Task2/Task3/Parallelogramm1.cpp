#include <iostream>
#include "Chetirehugolnik1.h"
#include "Parallelogramm1.h"

Parallelogramm::Parallelogramm(double a, double b, int A, int B) : Chetirehugolnik(a, b, a, b, A, B, A, B)
    {
        kol_storon = 4;
        name = "Параллелограмм";
        this->a = a;
        this->b = b;
        this->c = a;
        this->d = b;
        this->A = A;
        this->B = B;
        this->C = A;
        this->D = B;
    }
    void Parallelogramm::proverka()
    {
        if (A + B + C + D == 360 and a == c and b == d and A == C and B == D)
        {
            std::cout << "Правильная" << std::endl;
        }
        else
        {
            std::cout << "Неправильная" << std::endl;
        }
    }