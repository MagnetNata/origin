#include <iostream>

class Figura
{
protected:
    int kol_storon;
    std::string name;
public:
    Figura()
    {
        kol_storon = 0;
        name = "Фигура";
    }
    void print_information()
    {
        std::cout << name << ": " << kol_storon << std::endl;
    }
};

class Treugolnik: public Figura
{
public:
    Treugolnik()
    {
        kol_storon = 3;
        name = "Треугольник";
    }
};

class Chetirehugolnik : public Figura
{
public:
    Chetirehugolnik()
    {
        kol_storon = 4;
        name = "Четырехугольник";
    }
};

int main()
{
    setlocale(LC_ALL, "Rus");
    std::system("chcp 1251");
    Figura figura;
    Treugolnik treugolnik;
    Chetirehugolnik chetirehugolnik;
    std::cout << "Количество сторон:" << std::endl;
    figura.print_information();
    treugolnik.print_information();
    chetirehugolnik.print_information();
}
