#include <iostream>
using namespace std;

void count_sort(int* arr, int size)
{ 
    int* mas1 = new int[size];
    for (int i = 0; i < size; i++)
        mas1[i] = 0;
    int count[25];
    for (int i = 0; i < 25; i++)
        count[i] = 0;
    for (int i = 0; i < size; i++)
        count[arr[i]]++;
    for (int i = 1; i < 25; i++)
        count[i] += count[i - 1];
    for (int i = size - 1; i >= 0; i--)
    {
        mas1[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    for (int i = 0; i < size; i++)
        arr[i] = mas1[i];
}

void vvodMas(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "arr[" << i << "] = ";
        cin >> arr[i];
    }
    cout << endl;
}

void vivodMas(int* arr, int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int size;
    cout << "Введите количество элементов массива: " << endl;
    cin >> size;
    int* arr = new int[size];
    vvodMas(arr, size);


    cout << "Ваш массив: " << endl;
    vivodMas(arr, size);

    count_sort(arr, size);

    cout << "Отсортированный массив: " << endl;
    vivodMas(arr, size);
    return 0;
}