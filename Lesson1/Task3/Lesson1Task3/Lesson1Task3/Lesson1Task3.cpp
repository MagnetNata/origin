#include<iostream>

struct adress {
    std::string city;
    std::string street;
    int dom;
    int kvartira;
    int index;
};

void print_adress(adress* s1)
{
    std::cout << "______________________"<< std::endl;
    std::cout << "Город: " << s1->city << std::endl;
    std::cout << "Улица: " << s1->street << std::endl;
    std::cout << "Номер дома: " << s1->dom << std::endl;
    std::cout << "Номер квартиры: " << s1->kvartira << std::endl;
    std::cout << "Индекс: " << s1->index << std::endl;
    std::cout << "______________________" << std::endl << std::endl;
}

int main()
{
    setlocale(LC_ALL, "Rus");
    std::system("chcp 1251");
    adress s, x;
    s.city = "Москва";
    s.street = "Арбат";
    s.dom = 12;
    s.kvartira = 8;
    s.index = 123456;
    x.city = "Балашиха";
    x.street = "Ленина";
    x.dom = 154;
    x.kvartira = 25;
    x.index = 321548;
    print_adress(&s);
    print_adress(&x);
    return 0;
}