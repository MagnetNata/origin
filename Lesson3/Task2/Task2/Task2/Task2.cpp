#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

class adress
{
private:
    std::string gorod;
    std::string ulica;
    int dom;
    int kvartira;
public:
    adress()
    {
        gorod = "gorod";
        ulica = "ulica";
        dom = 0;
        kvartira = 0;
    }
    adress(std::string gorod, std::string ulica, int dom, int kvartira)
    {
        this->gorod = gorod;
        this->ulica = ulica;
        this->dom = dom;
        this->kvartira = kvartira;
    }
    void vvod_dannih(std::string gorod, std::string ulica, int dom, int kvartira)
    {
        this->gorod = gorod;
        this->ulica = ulica;
        this->dom = dom;
        this->kvartira = kvartira;
    }
    std::string return_gorod()
    {
        return gorod;
    }
    std::string return_ulica()
    {
        return ulica;
    }
    int return_dom()
    {
        return dom;
    }
    int return_kvartira()
    {
        return kvartira;
    }
};

int main()
{
    std::string gorod1;
    std::string ulica1;
    int dom1;
    int kvartira1;
    std::ifstream file("in.txt");
    bool res = file.is_open();
    if (res)
    {
        std::string s;
        file >> s;
        int kol;
        kol = stoi(s);
        adress* mas_s = new adress[kol];
        for (int i = 0; i < kol; i++)
        {
            file >> gorod1;
            file >> ulica1;
            file >> dom1;
            file >> kvartira1;
            mas_s[i].vvod_dannih(gorod1, ulica1, dom1, kvartira1);
        }
        file.close();
        std::ofstream file1("out.txt");
        file1 << s;
        file1 << std::endl;
        adress mas1;
        for (int j = 0; j < kol; j++)
        {
            for (int i = 0; i < kol - 1; i++)
            {
                if (mas_s[i].return_gorod() > mas_s[i + 1].return_gorod())
                {
                    mas1.vvod_dannih(mas_s[i].return_gorod(), mas_s[i].return_ulica(), mas_s[i].return_dom(), mas_s[i].return_kvartira());
                    mas_s[i].vvod_dannih(mas_s[i + 1].return_gorod(), mas_s[i + 1].return_ulica(), mas_s[i + 1].return_dom(), mas_s[i + 1].return_kvartira());
                    mas_s[i + 1].vvod_dannih(mas1.return_gorod(), mas1.return_ulica(), mas1.return_dom(), mas1.return_kvartira());
                }
            }
        }
        for (int i = 0; i < kol; i++)
        {
            file1 << mas_s[i].return_gorod() << ", ";
            file1 << mas_s[i].return_ulica() << ", ";
            file1 << std::to_string(mas_s[i].return_dom()) << ", ";
            file1 << std::to_string(mas_s[i].return_kvartira());
            file1 << std::endl;
        }
        delete[]mas_s;
        file1.close();
    }
    else
    {
        std::cout << "Не удалось открыть файл для чтения";
    }
}