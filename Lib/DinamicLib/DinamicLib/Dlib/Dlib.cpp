// Dlib.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include <iostream>
#include <string>
#include "DinamicLib.h"

int main()
{
	setlocale(LC_ALL, "Rus");
	std::system("chcp 1251");

	DinamicLib::Leaver leav;
	std::string name;
	std::cout << "Введите имя: ";
	std::cin >> name;
	std::cout << leav.leave(name) << std::endl;
}