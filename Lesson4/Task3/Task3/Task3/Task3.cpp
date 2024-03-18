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
    virtual void proverka()
    {
        std::cout << "Правильная" << std::endl;
    }
    int get_kol_storon()
    {
        return kol_storon;
    }
    std::string get_name()
    {
        return name;
    }
    virtual double get_a()
    {
        return 0;
    }
    virtual double get_b()
    {
        return 0;
    }
    virtual double get_c()
    {
        return 0;
    }
    virtual double get_d()
    {
        return 0;
    }
    virtual int get_A()
    {
        return 0;
    }
    virtual int get_B()
    {
        return 0;
    }
    virtual int get_C()
    {
        return 0;
    }
    virtual int get_D()
    {
        return 0;
    }
    virtual void print_information()
    {
        std::cout << name << ": " << std::endl;
        proverka();
        std::cout << "Количество сторон: " << kol_storon << std::endl;
        std::cout << std::endl;
    }
};

class Treugolnik : public Figura
{
protected:
    double a, b, c;
    int A, B, C;
public:
    Treugolnik(double a, double b, double c, int A, int B, int C) : Figura()
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
    void proverka() override
    {
        if (A + B + C == 180)
        {
            std::cout << "Правильная" << std::endl;
        }
        else
        {
            std::cout << "Неправильная" << std::endl;
        }
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
    void print_information() override
    {
        std::cout << name << ": " << std::endl;
        proverka();
        std::cout << "Количество сторон: " << kol_storon << std::endl;
        std::cout << "Стороны: a=" << get_a() << " b=" << get_b() << " c=" << get_c() << std::endl;
        std::cout << "Углы: А=" << get_A() << " B=" << get_B() << " C=" << get_C() << std::endl;
        std::cout << std::endl;
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
    void proverka() override
    {
        if (A + B + C + D == 360)
        {
            std::cout << "Правильная" << std::endl;
        }
        else
        {
            std::cout << "Неправильная" << std::endl;
        }
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
    void print_information() override
    {
        std::cout << name << ": " << std::endl;
        proverka();
        std::cout << "Количество сторон: " << kol_storon << std::endl;
        std::cout << "Стороны: a=" << get_a() << " b=" << get_b() << " c=" << get_c() << " d=" << get_d() << std::endl;
        std::cout << "Углы: А=" << get_A() << " B=" << get_B() << " C=" << get_C() << " D=" << get_D() << std::endl;
        std::cout << std::endl;
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
    void proverka() override
    {
        if (A + B + C == 180 and C==90)
        {
            std::cout << "Правильная" << std::endl;
        }
        else
        {
            std::cout << "Неправильная" << std::endl;
        }
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
    void proverka() override
    {
        if (A + B + C == 180 and a==c and A==C)
        {
            std::cout << "Правильная" << std::endl;
        }
        else
        {
            std::cout << "Неправильная" << std::endl;
        }
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
    void proverka() override
    {
        if (A + B + C == 180 and a==b and b==c and A==B and B==C)
        {
            std::cout << "Правильная" << std::endl;
        }
        else
        {
            std::cout << "Неправильная" << std::endl;
        }
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
    void proverka() override
    {
        if (A + B + C + D == 360 and a==c and b==d and A==C and B==D)
        {
            std::cout << "Правильная" << std::endl;
        }
        else
        {
            std::cout << "Неправильная" << std::endl;
        }
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
    void proverka() override
    {
        if (A + B + C + D == 360 and a == c and b == d and A == B and B == C and C == D)
        {
            std::cout << "Правильная" << std::endl;
        }
        else
        {
            std::cout << "Неправильная" << std::endl;
        }
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
    void proverka() override
    {
        if (A + B + C + D == 360 and a == b and b == c and c == d and A == B and B == C and C == D)
        {
            std::cout << "Правильная" << std::endl;
        }
        else
        {
            std::cout << "Неправильная" << std::endl;
        }
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
    void proverka() override
    {
        if (A + B + C + D == 360 and a == b and b == c and c == d and A == C and B == D)
        {
            std::cout << "Правильная" << std::endl;
        }
        else
        {
            std::cout << "Неправильная" << std::endl;
        }
    } 
};

int main()
{
    setlocale(LC_ALL, "Rus");
    std::system("chcp 1251");
    Figura* figura = new Figura();
    figura->print_information();
    delete(figura);
    Treugolnik* treugolnik = new Treugolnik(10, 20, 30, 50, 60, 70);
    treugolnik->print_information();
    delete(treugolnik);
    Pramoug_Treugolnik* pr_treugolnik = new Pramoug_Treugolnik(10, 20, 30, 50, 60);
    pr_treugolnik->print_information();
    delete(pr_treugolnik);
    Pramoug_Treugolnik* pr_treugolnik1 = new Pramoug_Treugolnik(10, 20, 30, 50, 40);
    pr_treugolnik1->print_information();
    delete(pr_treugolnik1);
    Ravnobed_Treugolnik* ravb_treugolnik = new Ravnobed_Treugolnik(10, 20, 50, 60);
    ravb_treugolnik->print_information();
    delete(ravb_treugolnik);
    Ravnostor_Treugolnik* ravs_treugolnik = new Ravnostor_Treugolnik(30);
    ravs_treugolnik->print_information();
    delete(ravs_treugolnik);
    Chetirehugolnik* chetirehugolnik = new Chetirehugolnik(10, 20, 30, 40, 50, 60, 70, 80);
    chetirehugolnik->print_information();
    delete(chetirehugolnik);
    Pryamougolnik* pryamougolnik = new Pryamougolnik(10, 20);
    pryamougolnik->print_information();
    delete(pryamougolnik);
    Kvadrat* kvadrat = new Kvadrat(20);
    kvadrat->print_information();
    delete(kvadrat);
    Parallelogramm* parallelogramm = new Parallelogramm(20, 30, 30, 40);
    parallelogramm->print_information();
    delete(parallelogramm);
    Romb* romb = new Romb(30, 30, 40);
    romb->print_information();
    delete(romb);
    
    
    
    
    
    
    
    
}
