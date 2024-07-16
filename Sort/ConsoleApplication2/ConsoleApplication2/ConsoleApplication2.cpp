#include <iostream>
using namespace std;

void quick_sort(int* arr, int size)
{
    int i = 0;
    int j = size - 1;
    int mid = arr[size / 2];
    do 
    {
        while (arr[i] < mid) 
            i++;
        while (arr[j] > mid) 
            j--;
        if (i <= j) 
        {
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    } while (i <= j);

    if (j > 0) 
        quick_sort(arr, j + 1);
    if (i < size) 
        quick_sort(&arr[i], size - i);
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

    quick_sort(arr, size);

    cout << "Отсортированный массив: " << endl;
    vivodMas(arr, size);
    return 0;
}