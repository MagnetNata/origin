#include <iostream>
#include "Figura1.h"
#include "Treugolnik1.h"
#include "Chetirehugolnik1.h"
#include "Pramoug_Treugolnik1.h"
#include "Ravnobed_Treugolnik1.h"
#include "Ravnostor_Treugolnik1.h"
#include "Parallelogramm1.h"
#include "Pryamougolnik1.h"
#include "Kvadrat1.h"
#include "Romb1.h"
#include "ErrorArgument1.h"

int main()
{
    setlocale(LC_ALL, "Rus");
    std::system("chcp 1251");
    try {
        Figura* figura = new Figura();
       // figura->print_information();
        delete(figura);
        Treugolnik* treugolnik = new Treugolnik(10, 20, 30, 50, 60, 70, "треугольник");
        delete(treugolnik);
        Pramoug_Treugolnik* pr_treugolnik = new Pramoug_Treugolnik(10, 20, 30, 30, 60, "прямоугольный треугольник");
       // pr_treugolnik->print_information();
        delete(pr_treugolnik);
        Pramoug_Treugolnik* pr_treugolnik1 = new Pramoug_Treugolnik(10, 20, 30, 50, 40, "прямоугольный треугольник");
       // pr_treugolnik1->print_information();
        delete(pr_treugolnik1);
        Ravnobed_Treugolnik* ravb_treugolnik = new Ravnobed_Treugolnik(10, 20, 30, 120, "равнобедренный треугольник");
       // ravb_treugolnik->print_information();
        delete(ravb_treugolnik);
        Ravnostor_Treugolnik* ravs_treugolnik = new Ravnostor_Treugolnik(30, "равносторонний треугольник");
       //ravs_treugolnik->print_information();
        delete(ravs_treugolnik);
        Chetirehugolnik* chetirehugolnik = new Chetirehugolnik(10, 20, 30, 40, 90, 90, 90, 90, "четырехугольник");
       // chetirehugolnik->print_information();
        delete(chetirehugolnik);
        Pryamougolnik* pryamougolnik = new Pryamougolnik(10, 20, "прямоугольник");
      //  pryamougolnik->print_information();
        delete(pryamougolnik);
        Kvadrat* kvadrat = new Kvadrat(20, "квадрат");
      //  kvadrat->print_information();
        delete(kvadrat);
        Parallelogramm* parallelogramm = new Parallelogramm(20, 30, 60, 120, "параллелограмм");
       // parallelogramm->print_information();
        delete(parallelogramm);
        Romb* romb = new Romb(30, 70, 110, "ромб");
       // romb->print_information();
        delete(romb);
    }
    catch (ErrorArgument ex)
    {
        std::cout << "Ошибка создания фигуры. Причина: " << ex.get_err() << std::endl;
    }








}
