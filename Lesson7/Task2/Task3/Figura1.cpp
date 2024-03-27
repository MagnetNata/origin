#include <iostream>
#include "Figura1.h"

Figura::Figura()
{
    kol_storon = 0;
    name = "Фигура";
}
void Figura::proverka()
{
    std::cout << "Правильная" << std::endl;
}
int Figura::get_kol_storon()
{
    return kol_storon;
}
std::string Figura::get_name()
{
    return name;
}
double Figura::get_a()
{
    return 0;
}
double Figura::get_b()
{
    return 0;
}
double Figura::get_c()
{
    return 0;
}
double Figura::get_d()
{
    return 0;
}
int Figura::get_A()
{
    return 0;
}
int Figura::get_B()
{
    return 0;
}
int Figura::get_C()
{
    return 0;
}
int Figura::get_D()
{
    return 0;
}
void Figura::print_information()
{
    std::cout << name << ": " << std::endl;
    proverka();
    std::cout << "Количество сторон: " << kol_storon << std::endl;
    std::cout << std::endl;
}