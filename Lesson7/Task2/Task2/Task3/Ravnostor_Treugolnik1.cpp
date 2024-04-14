#include <iostream>
#include "Treugolnik1.h"
#include "Ravnostor_Treugolnik1.h"
#include "ErrorArgument1.h"


Ravnostor_Treugolnik::Ravnostor_Treugolnik(double a, std::string name) : Treugolnik(a, a, a, 60, 60, 60, name)
    {
        kol_storon = 3;
        this->name = name;
       // std::cout << "Создаю фигуру: " << name << std::endl;
        this->a = a;
        this->b = a;
        this->c = a;
        this->A = 60;
        this->B = 60;
        this->C = 60;
        if (a != c and a!=b)
            throw ErrorArgument("Стороны не равны");
        if (A != C and A!=B)
            throw ErrorArgument("Углы не равны");
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
