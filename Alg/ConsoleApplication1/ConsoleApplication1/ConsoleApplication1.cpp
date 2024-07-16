
#include <iostream>

int calc(int* arr, int size, int toch)
{
    bool flag = false;
    int nach = 0; 
    int kon = size;
    int sred;

    while ((nach <= kon) && (flag == false)) {
        sred = (nach + kon) / 2; 

        if (arr[sred] == toch && arr[sred+1] > toch)
            flag = true; 
        if (arr[sred] > toch) 
            kon = sred - 1; 
        else 
            nach = sred + 1;
    }
    int kol = 0;
    for (int i = (sred+1); i < size; i++)
    {
        if (arr[i] > toch)
        {
            kol++;
        }
    }
    return kol;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int arr[9] = { 14, 16, 19, 32, 32, 32, 56, 69, 72 };
    int toch;
    std::cout << "Введите точку отсчёта: \n";
    std::cin >> toch;
    int kol;
    kol = calc(arr, 9, toch);
    std::cout << "Количество элементов в массиве больших, чем " << toch << " : " << kol;
}
