#include <iostream>
#include "Parallelogramm1.h"
#include "Pryamougolnik1.h"
#include "ErrorArgument1.h"


Pryamougolnik::Pryamougolnik(double a, double b, std::string name) : Parallelogramm(a, b, 90, 90, name)
    {
        kol_storon = 4;
        this->name = name;
       // std::cout << "Создаю фигуру: " << name << std::endl;
        this->a = a;
        this->b = b;
        this->c = a;
        this->d = b;
        this->A = 90;
        this->B = 90;
        this->C = 90;
        this->D = 90;
        if (a!=c and b!=d)
            throw ErrorArgument("Стороны попарно не равны");
        if (A!=90 and B!=90 and C!=90 and D!=90)
            throw ErrorArgument("Углы не равны 90");
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