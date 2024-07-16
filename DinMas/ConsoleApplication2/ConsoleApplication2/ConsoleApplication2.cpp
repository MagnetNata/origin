#include <iostream>
using namespace std;

int* append_to_dynamic_array(int* arr, int& logical_size, int& actual_size, int newEl)
{
    if (actual_size > logical_size)
    {
        arr[logical_size] = newEl;
        logical_size++;
        return arr;
    }
    else
    {
        int* arr1 = new int[actual_size*2];
        actual_size = actual_size * 2;
        for (int i = 0; i < logical_size; i++)
        {
            arr1[i] = arr[i];
        }
        arr1[logical_size] = newEl;
        logical_size++;
        delete[]arr;
        return arr1;
    }
}

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
    int newEl;
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
        do
        {
            cout << "Введите элемент для добавления : ";
            cin >> newEl;
            if (newEl != 0)
            {
                arr = append_to_dynamic_array(arr, logical_size, actual_size, newEl);
                print_dynamic_array(arr, logical_size, actual_size);
            }
        } while (newEl != 0);
        delete[]arr;
    }
}