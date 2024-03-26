#include <iostream>
using namespace std;
#define MODE 1

int add(int x, int y)
{
    return x + y;
}

int main() {
    setlocale(LC_ALL, "Rus");
    std::system("chcp 1251");
    int x, y;
#if defined MODE
#if MODE==0
    std::cout << "Работаю в режиме тренировки" << std::endl;
#elif MODE==1
    std::cout << "Работаю в боевом режиме" << std::endl;
    std::cout << "Введите число 1" << std::endl;
    std::cin >> x;
    std::cout << "Введите число 2" << std::endl;
    std::cin >> y;
    std::cout << "Результат сложения: " << add(x, y) << std::endl;
#else
    std::cout << "Неизвестный режим. Завершение работы" << std::endl;
#endif
#else
    std::cout << "Необходимо определить MODE" << std::endl;
#endif

    return 0;
}