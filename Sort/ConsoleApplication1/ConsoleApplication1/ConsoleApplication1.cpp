#include <iostream>
using namespace std;

void merge(int* arr, int left, int mid, int right)
{
    int mid1 = mid - left + 1;
    int mid2 = right - mid;

    int* arr1 = new int[mid1];
    int* arr2 = new int[mid2];

    for (int i = 0; i < mid1; i++)
        arr1[i] = arr[left + i];
    for (int j = 0; j < mid2; j++)
        arr2[j] = arr[mid + 1 + j];

    int i1 = 0, i2 = 0;

    int iMid = left;

    while (i1 < mid1 && i2 < mid2)
    {
        if (arr1[i1] <= arr2[i2])
        {
            arr[iMid] = arr1[i1];
            i1++;
        }
        else
        {
            arr[iMid] = arr2[i2];
            i2++;
        }
        iMid++;
    }

    while (i1 < mid1)
    {
        arr[iMid] = arr1[i1];
        i1++;
        iMid++;
    }

    while (i2 < mid2)
    {
        arr[iMid] = arr2[i2];
        i2++;
        iMid++;
    }
}

void mergeSort(int* arr,int begin, int end)
{
    if (begin >= end)
        return;

    int mid = begin + (end - begin) / 2;
    mergeSort(arr, begin, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, begin, mid, end);
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

    mergeSort(arr, 0, size-1);

    cout << "Отсортированный массив: " << endl;
    vivodMas(arr, size);
    return 0;
}