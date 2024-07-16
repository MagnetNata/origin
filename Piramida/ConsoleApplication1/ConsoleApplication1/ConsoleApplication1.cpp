#include <iostream>
#include <string>
using namespace std;

void vvodMas(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Введите arr[" << i << "] = ";
        cin >> arr[i];
    }
    cout << endl;
}

void print_Mas(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

}

void print_pyramid(int* arr, int size)
{
    int uroven;
    string child;
    int nom;
    for (int i = 0; i < size; i++)
    {
        if (i == 0)
        {
            uroven = 0;
            child = "root";
            cout << uroven << " " << child << " " << arr[i] << endl;
        }
        else
        {
            if (i % 2 != 0)
            {
                uroven++;
                child = "left";
            }
            else
            {
                child = "right";
            }
            nom = (i - 1) / 2;
            cout << uroven << " " << child << "(" << arr[nom] << ") " << arr[i] << endl;
        }
    }

}


int main()
{
    setlocale(LC_ALL, "Russian");
    int size;
    cout << "Введите размер массива: " << endl;
    cin >> size;
    int* arr = new int[size];
    vvodMas(arr, size);
    cout << "Исходный массив массив: " << endl;
    print_Mas(arr, size);
    cout << "Пирамида: " << endl;
    print_pyramid(arr, size);
    delete[]arr;
    return 0;
}