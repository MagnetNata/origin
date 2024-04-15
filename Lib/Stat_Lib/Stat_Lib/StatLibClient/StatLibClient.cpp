// StatLibClient.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<string>
#include<StatLib.h>

int main()
{
	setlocale(LC_ALL, "Rus");
	std::system("chcp 1251");

	StatLib::Greeter greeter;
	std::string name;
	std::cout << "Введите имя: ";
	std::cin >> name;
	std::cout << greeter.greet(name) << std::endl;
}