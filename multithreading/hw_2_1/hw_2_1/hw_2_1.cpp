#include <iostream>
#include <Windows.h>
#include <thread>
#include <ctime>
#include <atomic>
#include <mutex>

std::mutex m;

void first(std::atomic<int>& data)
{
    int end = data;
    m.lock();
    std::cout << "Первое окно начало свою работу!\n";
    std::cout << "Всего клиентов: " << data << std::endl;
    m.unlock();
    for (int i = 0; i < end; ++i)
    {
        ++data;
        m.lock();
        std::cout << " Очередь увеличелась, " << "вcего клиентов: " << data << std::endl;
        m.unlock();
        Sleep(500);
    }
    std::cout << "Первое окно закончило свою работу!\n" << std::endl;
}

void second(std::atomic<int>& data)
{
    m.lock();
    std::cout << "Второе окно начало свою работу!\n";
    std::cout << "Всего клиентов: " << data << std::endl;
    m.unlock();
    do
    {
        m.lock();
        --data;
        std::cout << " Очередь уменшилась, " << "вcего клиентов: " << data << std::endl;
        m.unlock();
        Sleep(1000);
    } while (data > 0);
    std::cout << "Второе окно закончило свою работу!\n" << std::endl;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::atomic<int > max_ = 10;
    auto now = std::chrono::system_clock::now();
    time_t time_now = std::chrono::system_clock::to_time_t(now);
    std::cout << "Время начала работы: ";
    printf("%02d:%02d:%02d \n", (int)(time_now / 3600 + 3) % 24, (int)(time_now / 60 % 60), (int)(time_now % 60));
    std::thread window1(first, max_);
    std::thread window2(second, max_);
    window1.join();
    window2.join();
    return 0;
}