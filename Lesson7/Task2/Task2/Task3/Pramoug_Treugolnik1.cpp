#include <iostream>
#include "Treugolnik1.h"
#include "Pramoug_Treugolnik1.h"
#include "ErrorArgument1.h"


Pramoug_Treugolnik::Pramoug_Treugolnik(double a, double b, double c, int A, int B, std::string name) : Treugolnik(a, b, c, A, B, 90, name)
    {
        kol_storon = 3;
        this->name = name;
        this->a = a;
        this->b = b;
        this->c = c;
        this->A = A;
        this->B = B;
        this->C = 90;
        if (C != 90)
            throw ErrorArgument("Угол C не равен 90");
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