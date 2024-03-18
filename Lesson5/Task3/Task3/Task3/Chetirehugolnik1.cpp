#include <iostream>
#include "Figura1.h"
#include "Chetirehugolnik1.h"


Chetirehugolnik::Chetirehugolnik(double a, double b, double c, double d, int A, int B, int C, int D)
    {
        kol_storon = 4;
        name = "Четырехугольник";
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
        this->A = A;
        this->B = B;
        this->C = C;
        this->D = D;
    }
    void Chetirehugolnik::proverka()
    {
        if (A + B + C + D == 360)
        {
            std::cout << "Правильная" << std::endl;
        }
        else
        {
            std::cout << "Неправильная" << std::endl;
        }
    }
    double Chetirehugolnik::get_a()
    {
        return a;
    }
    double Chetirehugolnik::get_b()
    {
        return b;
    }
    double Chetirehugolnik::get_c()
    {
        return c;
    }
    double Chetirehugolnik::get_d()
    {
        return d;
    }
    int Chetirehugolnik::get_A()
    {
        return A;
    }
    int Chetirehugolnik::get_B()
    {
        return B;
    }
    int Chetirehugolnik::get_C()
    {
        return C;
    }
    int Chetirehugolnik::get_D()
    {
        return D;
    }
    void Chetirehugolnik::print_information()
    {
        std::cout << name << ": " << std::endl;
        proverka();
        std::cout << "Количество сторон: " << kol_storon << std::endl;
        std::cout << "Стороны: a=" << get_a() << " b=" << get_b() << " c=" << get_c() << " d=" << get_d() << std::endl;
        std::cout << "Углы: А=" << get_A() << " B=" << get_B() << " C=" << get_C() << " D=" << get_D() << std::endl;
        std::cout << std::endl;
    }