#pragma once
class Figura
{
protected:
    int kol_storon;
    std::string name;
public:
    Figura();
    virtual void proverka();
    int get_kol_storon();
    std::string get_name();
    virtual double get_a();
    virtual double get_b();
    virtual double get_c();
    virtual double get_d();
    virtual int get_A();
    virtual int get_B();
    virtual int get_C();
    virtual int get_D();
    virtual void print_information();
};