#include <iostream>
#include "Figura1.h"
#include "Chetirehugolnik1.h"
#include "ErrorArgument1.h"


Chetirehugolnik::Chetirehugolnik(double a, double b, double c, double d, int A, int B, int C, int D, std::string name)
    {
        kol_storon = 4;
        this->name = name;
        std::cout << "Создаю фигуру: " << name << std::endl;
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
        this->A = A;
        this->B = B;
        this->C = C;
        this->D = D;
        if (kol_storon != 4)
            throw ErrorArgument("Количество сторон треугольника не равно трем");
        if (A + B + C + D != 360)
            throw ErrorArgument("Сумма углов треугольника не равна 360");
        std::cout << name << "(";
        std::cout << "cтороны " << get_a() << ", " << get_b() << " , " << get_c() << " , " << get_d();
        std::cout << "; углы " << get_A() << ", " << get_B() << ", " << get_C() << ", " << get_D() << ")";
        std::cout << " создан" << std::endl;
        std::cout << std::endl;
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
        //std::cout << name << ": " << std::endl;
       // proverka();
       /* std::cout << "Количество сторон: " << kol_storon << std::endl;
        std::cout << "Стороны: a=" << get_a() << " b=" << get_b() << " c=" << get_c() << " d=" << get_d() << std::endl;
        std::cout << "Углы: А=" << get_A() << " B=" << get_B() << " C=" << get_C() << " D=" << get_D() << std::endl;
        std::cout << std::endl;*/
    }