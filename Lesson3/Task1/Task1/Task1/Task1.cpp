#include <iostream>
#include <fstream>
#include <string>

struct adress
{
    std::string gorod;
    std::string ulica;
    int dom;
    int kvartira;
};

int main()
{
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
            file >> mas_s[i].gorod;
            file >> mas_s[i].ulica;
            file >> mas_s[i].dom;
            file >> mas_s[i].kvartira;
        }
        file.close();
        std::ofstream file1("out.txt");
        file1 << s;
        file1 << std::endl;
        for (int i = 0; i < kol; i++)
        {
            file1 << mas_s[i].gorod << ", ";
            file1 << mas_s[i].ulica << ", ";
            file1 << std::to_string(mas_s[i].dom) << ", ";
            file1 << std::to_string(mas_s[i].kvartira);
            file1 << std::endl;
        }
        delete[] mas_s;
        file1.close();
    }
    else
    {
        std::cout << "Не удалось открыть файл для чтения";
    }
}