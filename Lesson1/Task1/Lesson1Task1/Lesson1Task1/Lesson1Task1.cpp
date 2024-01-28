#include<iostream>

enum month {
    End,
    January,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December
};

int main()
{
    setlocale(LC_ALL, "Rus");
    int num;
    do {
        std::cout << "Введите номер месяца:";
        std::cin >> num;
        switch (num)
        {
        case End:
            std::cout << "\nДо свидания!\n";
            break;
        case January:
            std::cout << "\nЯнварь\n";
            break;
        case February:
            std::cout << "\nФевраль\n";
            break;
        case March:
            std::cout << "\nМарт\n";
            break;
        case April:
            std::cout << "\nАпрель\n";
            break;
        case May:
            std::cout << "\nМай\n";
            break;
        case June:
            std::cout << "\nИюнь\n";
            break;
        case July:
            std::cout << "\nИюль\n";
            break;
        case August:
            std::cout << "\nАвгуст\n";
            break;
        case September:
            std::cout << "\nСентябрь\n";
            break;
        case October:
            std::cout << "\nОктябрь\n";
            break;
        case November:
            std::cout << "\nНоябрь\n";
            break;
        case December:
            std::cout << "\nДекабрь\n";
            break;
        default:
            std::cout << "\nНеправильный номер!\n";
        }
    } while (num != 0);
    return 0;
}