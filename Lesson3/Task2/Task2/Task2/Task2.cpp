#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

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
        std::string* str = new std::string[kol];
        for (int i = 0; i < kol; i++)
        {
            str[i] = mas_s[i].gorod + ", " + mas_s[i].ulica + ", " + std::to_string(mas_s[i].dom) + ", " + std::to_string(mas_s[i].kvartira);
        }
        for (int i = 0; i < kol; i++) {
            for (int j = 0; j < kol-1; j++) {
                if (str[j] > str[j + 1]) {
                    std::string b = str[j]; 
                    str[j] = str[j + 1]; 
                    str[j + 1] = b; 
                }
            }
        }
        std::ofstream file1("out.txt");
        file1 << s;
        file1 << std::endl;
        for (int i = 0; i < kol; i++)
        {
            file1 << str[i];
            file1 << std::endl;
        }
        delete[] str;
        delete[] mas_s;
        file1.close();
    }
    else
    {
        std::cout << "Не удалось открыть файл для чтения";
    }
}