#include <iostream>
using namespace std;

class ErrorLength : public std::exception
{
public:
    const char* what() const override
    {
        return "Вы ввели слово запретной длины! До свидания";
    }
};

int function(std::string str, int forbidden_length)
{
    int Slen;
    Slen = static_cast<int> (str.length());
    if (Slen == forbidden_length)
    {
        throw ErrorLength();
    }
    return Slen;
}

int main() {
    setlocale(LC_ALL, "Rus");
    std::system("chcp 1251");
    int forbidden_length;
    std::string str;
    int Slen;
    std::cout << "Введите запретную длину: ";
    std::cin >> forbidden_length;
    try
    {
        while (true)
        {
            std::cout << "\nВведите слово: ";
            std::cin >> str;
            Slen = function(str, forbidden_length);
            std::cout << "\nДлина слова \"" << str << "\" равна " << Slen;
        }
    }
    catch (const ErrorLength &ex)
    {
        std::cout << ex.what() << std::endl;
    }

    return 0;
}