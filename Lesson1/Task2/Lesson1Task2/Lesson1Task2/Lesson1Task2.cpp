#include<iostream>

struct schet {
    int nomer;
    std::string name;
    double kol;
};

void change_schet(schet* s1, int new_kol)
{
    s1->kol = new_kol;
}

int main()
{
    setlocale(LC_ALL, "Rus");
    std::system("chcp 1251");
    schet s;
    int kol1;
    std::cout << "Введите номер счёта: ";
    std::cin >> s.nomer;
    std::cout << std::endl<< "Введите имя владельца: ";
    std::cin >> s.name;
    std::cout << std::endl<< "Введите баланс: ";
    std::cin >> s.kol;
    std::cout << std::endl<< "Введите новый баланс: ";
    std::cin >> kol1;
    change_schet(&s, kol1);
    std::cout << "Ваш счёт: " << s.name << ", " << s.nomer << ", " << s.kol << std::endl;
    return 0;
}