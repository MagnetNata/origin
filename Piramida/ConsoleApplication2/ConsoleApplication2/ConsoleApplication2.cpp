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
                nom = (i - 1) / 2;
            }
            else
            {
                child = "right";
                nom = (i - 2) / 2;
            }
            cout << uroven << " " << child << "(" << arr[nom] << ") " << arr[i] << endl;
        }
    }

}

bool roditel(int* arr, int poziciya, int& poziciya_rod)
{
    if (poziciya % 2 == 0)
        poziciya_rod = (poziciya - 2) / 2;
    else
        poziciya_rod = (poziciya - 1) / 2;
    if (poziciya_rod < 0)
        return false;
    else
        return true;
}

bool left_pot(int* arr, int size, int poziciya, int& poziciya_rod)
{
    poziciya_rod = (poziciya * 2) + 1;
    if (poziciya_rod < size)
        return true;
    else
        return false;
}

bool right_pot(int* arr, int size, int poziciya, int& poziciya_rod)
{
    poziciya_rod = (poziciya * 2) + 2;
    if (poziciya_rod < size)
        return true;
    else
        return false;
}


int main()
{
    int uroven = 0;
    int poziciya = 0;
    int poziciya_rod;
    int nom;
    string child = "root";
    string komanda;
    bool rez;
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
    do {
        if (poziciya == 0)
            cout << "Вы находитесь здесь: " << uroven << " " << child << " " << arr[poziciya] << endl;
        else
            cout << "Вы находитесь здесь: " << uroven << " " << child << "(" << arr[nom] << ") " << arr[poziciya] << endl;
        cout << "Введите команду: ";
        cin >> komanda;
        if (komanda == "up")
        {
            rez = roditel(arr, poziciya, poziciya_rod);
            if (rez)
            {
                cout << "OK" << endl;
                uroven--;
                poziciya = poziciya_rod;
                if (poziciya==0)
                    child = "root";
                else
                {
                    if (poziciya % 2 != 0)
                    {
                        child = "left";
                        nom = (poziciya - 1) / 2;
                    }
                    else
                    {
                        child = "right";
                        nom = (poziciya - 2) / 2;
                    }
                }
            }
            else
            {
                cout << "Ошибка! Отсутствует родитель" << endl;
            }
        }

        if (komanda == "left")
        {
            rez = left_pot(arr, size, poziciya, poziciya_rod);
            if (rez)
            {
                cout << "OK" << endl;
                uroven++;
                poziciya = poziciya_rod;
                child = "left";
                nom = (poziciya - 1) / 2;
            }
            else
            {
                cout << "Ошибка! Отсутствует левый потомок" << endl;
            }
        }
        if (komanda == "right")
        {
            rez = right_pot(arr, size, poziciya, poziciya_rod);
            if (rez)
            {
                cout << "OK" << endl;
                uroven++;
                poziciya = poziciya_rod;
                child = "right";
                nom = (poziciya - 2) / 2;
            }
            else
            {
                cout << "Ошибка! Отсутствует правый потомок" << endl;
            }
        }
        if (komanda == "exit")
        {
            cout << "До свидания!" << endl;
        }

    } while (komanda != "exit");
    delete[]arr;
    return 0;
}