#include <iostream>
#include "Figura1.h"
#include "Treugolnik1.h"

Treugolnik::Treugolnik(double a, double b, double c, int A, int B, int C) : Figura()
{
        kol_storon = 3;
        name = "Треугольник";
        this->a = a;
        this->b = b;
        this->c = c;
        this->A = A;
        this->B = B;
        this->C = C;
}
    void Treugolnik::proverka()
    {
        if (A + B + C == 180)
        {
            std::cout << "Правильная" << std::endl;
        }
        else
        {
            std::cout << "Неправильная" << std::endl;
        }
    }
    double Treugolnik::get_a()
    {
        return a;
    }
    double Treugolnik::get_b()
    {
        return b;
    }
    double Treugolnik::get_c()
    {
        return c;
    }
    int Treugolnik::get_A()
    {
        return A;
    }
    int Treugolnik::get_B()
    {
        return B;
    }
    int Treugolnik::get_C()
    {
        return C;
    }
    void Treugolnik::print_information()
    {
        std::cout << name << ": " << std::endl;
        proverka();
        std::cout << "Количество сторон: " << kol_storon << std::endl;
        std::cout << "Стороны: a=" << get_a() << " b=" << get_b() << " c=" << get_c() << std::endl;
        std::cout << "Углы: А=" << get_A() << " B=" << get_B() << " C=" << get_C() << std::endl;
        std::cout << std::endl;
    }