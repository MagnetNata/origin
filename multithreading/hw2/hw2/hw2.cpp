#include <iostream>
#include<Windows.h>
#include<vector>
#include<algorithm>
#include<chrono>
#include<thread>
#include<execution>

void massiv(std::vector<int> a, int size)
{
    for (int i = 0; i < size; ++i)
    {
        a.push_back(i);
    };
}

void summ_vect(std::vector<int> a, std::vector<int> b, int start, int stop)
{
    for (int i = start; i < stop; ++i) int c = a[i] + b[i];
}

void time_thread(std::vector<double>& time_count, int count, std::vector<int> a, std::vector<int> b, int threads)
{

    std::vector<std::thread> completion_threads;
    int n = static_cast<int>(a.size() / threads);
    std::vector<int> start_stop{ 0 };
    for (int q = 0; q < threads - 1; ++q) 
    {
        start_stop.push_back(q * n);
    };
    start_stop.push_back(a.size() - 1);
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < threads; i++)
    {
        completion_threads.push_back(std::thread(summ_vect, a, b, start_stop[i], start_stop[i + 1] - 1));
    };
    for (auto& t : completion_threads)
    {
        t.join();
    };
    auto now = std::chrono::high_resolution_clock::now();
    auto k = std::chrono::duration_cast<std::chrono::nanoseconds>(now - start);
    double u = static_cast<double>(k.count()) / 1000000;
    time_count.push_back(u);
}

void print_table(std::vector<double>& time_count, std::vector<int> threads, std::vector<int> size)
{
    std::cout << " \t\t\t\t\t\t\t Размер массивов для сложения" << std::endl;
    std::cout << "\t\t\t   ";
    for (auto i : size) { std::cout << "" << i << "\t\t"; };
    std::cout << std::endl << "Количесво потоков \t Время затрачиваемое на работу (милисекунд)" << std::endl;
    int j = 0;
    for (int i = 0; i < threads.size(); ++i)
    {
        std::cout << "\t" << threads[i] << " потоков";
        for (int f = 0; f < size.size(); ++f)
        {
            printf("  \t%4.4f ", time_count[j]);
            ++j;
        };
        std::cout << std::endl;
    };
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::cout << "Количество доступных потоков: " << std::thread::hardware_concurrency() << std::endl;
    auto now = std::chrono::system_clock::now();
    time_t now_t = std::chrono::system_clock::to_time_t(now);
    std::cout << "Время начала работы: " << (now_t / 3600 + 3) % 24 << ":" << (now_t / 60 % 60) << ":" << now_t % 60 << std::endl; 
    std::vector<double> time_count;
    std::vector<int> size{ 1000,10000,100000,1000000,10000000 };
    std::vector<int> threads{ 1,2,4,8,16 };
    for (auto i : threads)
    {
        for (auto j : size)
        {
            std::vector<int> a, b;
            massiv(a, j);
            massiv(b, j);
            time_thread(time_count, j, a, b, i);
        };
    };
    print_table(time_count, threads, size);
}