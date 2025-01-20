#include <iostream>
#include <Windows.h>
#include<thread>
#include <ctime>
void first(int start)
{
    int end = start;
    std::cout << "Первое окно начало свою работу!\n";
    for (int i = 0; i < end; ++i)
    {
        ++start;
        Sleep(1000);
    }
    std::cout << "Первое окно закончило свою работу!\n" << std::endl;
}
void second(int start)
{
    std::cout << "Второе окно начало свою работу!\n";
    do
    {
        --start;
        Sleep(2000);
    } while (start > 0);
    std::cout << "Второе окно закончило свою работу!\n" << std::endl;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int max_ = 10;
    auto now = std::chrono::system_clock::now();
    time_t time_now = std::chrono::system_clock::to_time_t(now);
    std::cout << "Время начала работы: ";
    printf("%02d:%02d:%02d \n", (time_now / 3600 + 3) % 24, (time_now / 60 % 60), time_now % 60);
    std::thread window1(first, max_);
    std::thread window2(second, max_);
    window1.join();
    window2.join();
    return 0;
}