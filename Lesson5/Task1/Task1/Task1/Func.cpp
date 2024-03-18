#include <iostream>
#include "Func.h"
using namespace std;

void add(double num1, double num2)
{
    std::cout << "\n" << num1 << " + " << num2 << " = " << num1 + num2;
}
void subtract(double num1, double num2)
{
    std::cout << "\n" << num1 << " - " << num2 << " = " << num1 - num2;
}
void multiply(double num1, double num2)
{
    std::cout << "\n" << num1 << " * " << num2 << " = " << num1 * num2;
}
void divide(double num1, double num2)
{
    if (num2 != 0)
    {
        std::cout << "\n" << num1 << " : " << num2 << " = " << num1 / num2;
    }
    else
    {
        std::cout << "На ноль делить нельзя\n";
    }
}
void stepen(double num1, double num2)
{
    std::cout << "\n" << num1 << " в степени " << num2 << " = " << pow(num1,num2);
}