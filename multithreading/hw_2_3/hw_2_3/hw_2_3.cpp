#include "Data.h"
#include <iostream>
#include <vector>
#include <Windows.h>
#include <thread>
#include <mutex>


void swapWithLock(Data& d1, Data& d2)
{
    std::lock(d1.mutex1, d2.mutex1);
    std::lock_guard<std::mutex>L1{ d1.mutex1, std::adopt_lock };
    std::lock_guard<std::mutex>L2{ d2.mutex1, std::adopt_lock };

    int tmp = d1.getValue();
    d1.setValue(d2.getValue());
    d2.setValue(tmp);

    std::cout << std::endl << "ID потока: " << std::this_thread::get_id() << " после функции: " __FUNCTION__ << std::endl;
    std::cout << "value1 = " << d1.getValue() << ";" << std::endl;
    std::cout << "value1 = " << d2.getValue() << ";" << std::endl;
}

void swapWithScopedLock(Data& d1, Data& d2)
{
    std::scoped_lock lock(d1.mutex1, d2.mutex1);

    int tmp = d1.getValue();
    d1.setValue(d2.getValue());
    d2.setValue(tmp);

    std::cout << std::endl << "ID потока: " << std::this_thread::get_id() << " после функции: " __FUNCTION__ << std::endl;
    std::cout << "value1 = " << d1.getValue() << ";" << std::endl;
    std::cout << "value1 = " << d2.getValue() << ";" << std::endl;
}

void swapWithUniqueLock(Data& d1, Data& d2)
{
    std::unique_lock<std::mutex> lock1(d1.mutex1, std::defer_lock);
    std::unique_lock<std::mutex> lock2(d2.mutex1, std::defer_lock);
    std::lock(lock1, lock2);

    int tmp = d1.getValue();
    d1.setValue(d2.getValue());
    d2.setValue(tmp);

    std::cout << std::endl << "ID потока: " << std::this_thread::get_id() << " после функции: " __FUNCTION__ << std::endl;
    std::cout << "value1 = " << d1.getValue() << ";" << std::endl;
    std::cout << "value1 = " << d2.getValue() << ";" << std::endl;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::cout << "ID потока: " << std::this_thread::get_id() << "\n";

    Data d1(111);
    Data d2(222);

    std::cout << "\nИзначально:\n";
    std::cout << "value1 = " << d1.getValue() << ";" << std::endl;
    std::cout << "value1 = " << d2.getValue() << ";" << std::endl;

    std::thread thread1(swapWithLock, std::ref(d1), std::ref(d2));
    std::thread thread2(swapWithScopedLock, std::ref(d1), std::ref(d2));
    std::thread thread3(swapWithUniqueLock, std::ref(d1), std::ref(d2));

    thread1.join();
    thread2.join();
    thread3.join();

    std::cout << "\n\n\n";
}