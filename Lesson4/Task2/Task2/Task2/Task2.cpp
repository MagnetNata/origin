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
    int get_kol_storon()
    {
        return kol_storon;
    }
    std::string get_name()
    {
        return name;
    }
    double virtual get_a()
    {
        return 0;
    }
    double virtual get_b()
    {
        return 0;
    }
    double virtual get_c()
    {
        return 0;
    }
    double virtual get_d()
    {
        return 0;
    }
    int virtual get_A()
    {
        return 0;
    }
    int virtual get_B()
    {
        return 0;
    }
    int virtual get_C()
    {
        return 0;
    }
    int virtual get_D()
    {
        return 0;
    }
};

class Treugolnik : public Figura
{
protected:
    double a, b, c;
    int A, B, C;
public:
    Treugolnik(double a, double b, double c, int A, int B, int C): Figura()
    {
        kol_storon = 3;
        name = "Треугольник";
        this->a = a;
        this->b = b;
        this->c = c;
        this->A = A;
        this->B = B;
        this->C = C;
    }
    double get_a()
    {
        return a;
    }
    double get_b()
    {
        return b;
    }
    double get_c()
    {
        return c;
    }
    int get_A()
    {
        return A;
    }
    int get_B()
    {
        return B;
    }
    int get_C()
    {
        return C;
    }
};

class Chetirehugolnik : public Figura
{
protected:
    double a, b, c, d;
    int A, B, C, D;
public:
    Chetirehugolnik(double a, double b, double c, double d, int A, int B, int C, int D)
    {
        kol_storon = 4;
        name = "Четырехугольник";
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
        this->A = A;
        this->B = B;
        this->C = C;
        this->D = D;
    }
    double get_a()
    {
        return a;
    }
    double get_b()
    {
        return b;
    }
    double get_c()
    {
        return c;
    }
    double get_d()
    {
        return d;
    }
    int get_A()
    {
        return A;
    }
    int get_B()
    {
        return B;
    }
    int get_C()
    {
        return C;
    }
    int get_D()
    {
        return D;
    }
};

class Pramoug_Treugolnik : public Treugolnik
{
protected:
    double a, b, c;
    int A, B, C;
public:
    Pramoug_Treugolnik(double a, double b, double c, int A, int B) : Treugolnik(a, b, c, A, B, 90)
    {
        kol_storon = 3;
        name = "Прямоугольный треугольник";
        this->a = a;
        this->b = b;
        this->c = c;
        this->A = A;
        this->B = B;
        this->C = 90;
    }
};

class Ravnobed_Treugolnik : public Treugolnik
{
protected:
    double a, b, c;
    int A, B, C;
public:
    Ravnobed_Treugolnik(double a, double b, int A, int B) : Treugolnik(a, b, a, A, B, A)
    {
        kol_storon = 3;
        name = "Равнобедренный треугольник";
        this->a = a;
        this->b = b;
        this->c = a;
        this->A = A;
        this->B = B;
        this->C = A;
    }
};

class Ravnostor_Treugolnik : public Treugolnik
{
protected:
    double a, b, c;
    int A, B, C;
public:
    Ravnostor_Treugolnik(double a) : Treugolnik(a, a, a, 60, 60, 60)
    {
        kol_storon = 3;
        name = "Равносторонний треугольник";
        this->a = a;
        this->b = a;
        this->c = a;
        this->A = 60;
        this->B = 60;
        this->C = 60;
    }
};

class Parallelogramm : public Chetirehugolnik
{
protected:
    double a, b, c, d;
    int A, B, C, D;
public:
    Parallelogramm(double a, double b, int A, int B) : Chetirehugolnik(a, b, a, b, A, B, A, B)
    {
        kol_storon = 4;
        name = "Параллелограмм";
        this->a = a;
        this->b = b;
        this->c = a;
        this->d = b;
        this->A = A;
        this->B = B;
        this->C = A;
        this->D = B;
    }
};

class Pryamougolnik : public Parallelogramm
{
protected:
    double a, b, c, d;
    int A, B, C, D;
public:
    Pryamougolnik(double a, double b) : Parallelogramm(a, b, 90, 90)
    {
        kol_storon = 4;
        name = "Прямоугольник";
        this->a = a;
        this->b = b;
        this->c = a;
        this->d = b;
        this->A = 90;
        this->B = 90;
        this->C = 90;
        this->D = 90;
    }
};

class Kvadrat : public Pryamougolnik
{
protected:
    double a, b, c, d;
    int A, B, C, D;
public:
    Kvadrat(double a) : Pryamougolnik(a, a)
    {
        kol_storon = 4;
        name = "Квадрат";
        this->a = a;
        this->b = a;
        this->c = a;
        this->d = a;
        this->A = 90;
        this->B = 90;
        this->C = 90;
        this->D = 90;
    }
};

class Romb : public Parallelogramm
{
protected:
    double a, b, c, d;
    int A, B, C, D;
public:
    Romb(double a, int A, int B) : Parallelogramm(a, a, A, B)
    {
        kol_storon = 4;
        name = "Ромб";
        this->a = a;
        this->b = a;
        this->c = a;
        this->d = a;
        this->A = A;
        this->B = B;
        this->C = A;
        this->D = B;
    }
};

void print_information(Figura* x)
{
    std::cout << x->get_name() << ": " << std::endl;
    if (x->get_kol_storon() == 3)
    {
        std::cout << "Стороны: a=" << x->get_a() << " b=" << x->get_b() << " c=" << x->get_c() << std::endl;
        std::cout << "Углы: А=" << x->get_A() << " B=" << x->get_B() << " C=" << x->get_C() << std::endl << std::endl;
    }
    else
    {
        std::cout << "Стороны: a=" << x->get_a() << " b=" << x->get_b() << " c=" << x->get_c() << " d=" << x->get_d() << std::endl;
        std::cout << "Углы: А=" << x->get_A() << " B=" << x->get_B() << " C=" << x->get_C() << " D=" << x->get_D() << std::endl << std::endl;
    }
}

int main()
{
    setlocale(LC_ALL, "Rus");
    std::system("chcp 1251");
    Treugolnik* treugolnik = new Treugolnik(10,20,30,50,60,70);
    print_information(treugolnik);
    Pramoug_Treugolnik* pr_treugolnik = new Pramoug_Treugolnik(10, 20, 30, 50, 60);
    print_information(pr_treugolnik);
    Ravnobed_Treugolnik* ravb_treugolnik = new Ravnobed_Treugolnik(10, 20, 50, 60);
    print_information(ravb_treugolnik);
    Ravnostor_Treugolnik* ravs_treugolnik = new Ravnostor_Treugolnik(30);
    print_information(ravs_treugolnik);
    Chetirehugolnik* chetirehugolnik = new Chetirehugolnik(10,20,30,40,50,60,70,80);
    print_information(chetirehugolnik);
    Pryamougolnik* pryamougolnik = new Pryamougolnik(10, 20);
    print_information(pryamougolnik);
    Kvadrat* kvadrat = new Kvadrat(20);
    print_information(kvadrat);
    Parallelogramm* parallelogramm = new Parallelogramm(20, 30, 30, 40);
    print_information(parallelogramm);
    Romb* romb = new Romb(30, 30, 40);
    print_information(romb);

    delete(romb);
    delete(parallelogramm);
    delete(kvadrat);
    delete(pryamougolnik);
    delete(chetirehugolnik);
    delete(ravs_treugolnik);
    delete(ravb_treugolnik);
    delete(pr_treugolnik);
    delete(treugolnik);
}
