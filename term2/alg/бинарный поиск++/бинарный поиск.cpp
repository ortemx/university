#include <iostream>
#include <algorithm>
#include <windows.h>
#include <ctime>
#include <iomanip>

using namespace std;

void init(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        arr[i]=rand()%195;
}

void print(int *arr, int n)
{
    cout<<endl;
    for (int i = 0; i < n; i++)
        cout<<setw(4)<<arr[i];
}

void SORT(int *arr, int n)
{
     sort (arr, arr + n);
}

int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(NULL));

    int n=415;
    //cin>>n;

    int *arr = new int [n];

    init(arr, n);
    print(arr, n);
    SORT(arr, n);
    print(arr, n);

    int key; // создали переменную в которой будет находиться ключ

    cout << endl << "Введите ключ: ";
    cin >> key; // считываем ключ

    bool flag = false;
    int l = 0; // левая граница
    int r = n-1; // правая граница
    int mid;

    while ((l <= r) && (flag != true))
    {
        mid = (l + r) / 2; // считываем срединный индекс отрезка [l,r]
        if (arr[mid] == key)
            flag = true; //проверяем ключ со серединным элементом
        (arr[mid] > key) ? r = mid - 1 : l = mid + 1;
    }
    (flag) ? cout << "Индекс элемента " << key << " в массиве равен: " << mid
    : cout << "такого элемента в массиве нет";

    delete[] arr;

    return 0;
}
