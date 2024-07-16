#include <iostream>
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

void print_dynamic_array(int* arr, int logical_size, int actual_size)
{
    for (int i = 0; i < actual_size; i++)
    {
        if (i < logical_size)
            cout << arr[i] << " ";
        else
            cout << "_ ";
    }
    cout << endl;

}

void main()
{
    setlocale(LC_ALL, "Russian");
    int logical_size;
    int actual_size;
    cout << "Введите фактичеcкий размер массива: " << endl;
    cin >> actual_size;
    cout << "Введите логический массива: " << endl;
    cin >> logical_size;
    if (logical_size > actual_size)
        cout << "Ошибка! Логический размер массива не может превышать фактический!" << endl;
    else
    {
        int* arr = new int[actual_size];
        vvodMas(arr, logical_size);
        cout << "Ваш массив: " << endl;
        print_dynamic_array(arr, logical_size, actual_size);

        delete[]arr;
    }
}