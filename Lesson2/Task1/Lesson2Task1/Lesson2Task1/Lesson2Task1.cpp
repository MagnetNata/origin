#include <iostream>
using namespace std;

class Calculator 
{
 public:
    double num1;
    double num2;
    Calculator()
    {
        num1 = 1;
        num2 = 1;
    }
    Calculator(double x, double y)
    {
        num1 = x;
        num2 = y;
    }
    double add()
    {
        return num1 + num2;
    }
    double multiply()
    {
        return num1 * num2;
    }
    double subtract_1_2()
    {
        return num2 - num1;
    }
    double subtract_2_1()
    {
        return num1 - num2;
    }
    double divide_1_2()
    {
        return num1 / num2;
    }
    double divide_2_1()
    {
        return num2 / num1;
    }
    bool set_num1(double num1)
    {
        if (num1 == 0)
        {   
            return false;
        }
        else
        {
            this->num1 = num1;
            return true;
        }
    }
    bool set_num2(double num2)
    {
        if (num2 == 0)
        {
            return false;
        }
        else
        {
            this->num2 = num2;
            return true;
        }
    }

};

int main()
{
    setlocale(LC_ALL, "Rus");
    std::system("chcp 1251");
    double x;
    bool rez;
    Calculator calc;
    while (true)
    {
        std::cout << "\nВведите два числа";
        do
        {
            std::cout << "\nВведите первое число: ";
            std::cin >> x;
            rez = calc.set_num1(x);
        } while (rez == false);
        do
        {
            std::cout << "\nВведите второе число: ";
            std::cin >> x;
            rez = calc.set_num2(x);
        } while (rez == false);

        std::cout << "\n" << calc.num1 << " + " << calc.num2 << " = " << calc.add();
        std::cout << "\n" << calc.num1 << " - " << calc.num2 << " = " << calc.subtract_2_1();
        std::cout << "\n" << calc.num2 << " - " << calc.num1 << " = " << calc.subtract_1_2();
        std::cout << "\n" << calc.num1 << " * " << calc.num2 << " = " << calc.multiply();
        std::cout << "\n" << calc.num1 << " / " << calc.num2 << " = " << calc.divide_1_2();
        std::cout << "\n" << calc.num2 << " / " << calc.num1 << " = " << calc.divide_2_1();
    };
    return 0;
}