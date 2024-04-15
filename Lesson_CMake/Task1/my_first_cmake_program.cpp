#include <iostream>
#include <string>

int main(int args, char** argv)
{
	setlocale(LC_ALL, "Rus");
	std::system("chcp 1251");
	std::string name;
	std::cout << "Введите имя: ";
	std::cin >> name;
	std::cout << "Здравствуйте, " << name << std::endl;
	return 0;
}