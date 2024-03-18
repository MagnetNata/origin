#include <iostream>
#include "Func.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    std::system("chcp 1251");
    double x,y;
    int oper;
    std::cout << "\nВведите два числа";
    std::cout << "\nВведите первое число: ";
    std::cin >> x;
    std::cout << "\nВведите второе число: ";
    std::cin >> y;
    std::cout << "\nВыберите операцию(1 - сложение, 2 вычитание, 3 - умножение, 4 - деление, 5 - возведение в степень): ";
    std::cin >> oper;
    switch (oper)
    {
        case 1:
            add(x, y);
            break;
        case 2:
            subtract(x, y);
            break;
        case 3:
            multiply(x, y);
            break;
        case 4:
            divide(x, y);
            break;
        case 5:
            stepen(x, y);
            break;
        default:
            std::cout << "\nНет такой операции";
            break;
    }
    return 0;
}