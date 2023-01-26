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

    int key; // ������� ���������� � ������� ����� ���������� ����

    cout << endl << "������� ����: ";
    cin >> key; // ��������� ����

    bool flag = false;
    int l = 0; // ����� �������
    int r = n-1; // ������ �������
    int mid;

    while ((l <= r) && (flag != true))
    {
        mid = (l + r) / 2; // ��������� ��������� ������ ������� [l,r]
        if (arr[mid] == key)
            flag = true; //��������� ���� �� ���������� ���������
        (arr[mid] > key) ? r = mid - 1 : l = mid + 1;
    }
    (flag) ? cout << "������ �������� " << key << " � ������� �����: " << mid
    : cout << "������ �������� � ������� ���";

    delete[] arr;

    return 0;
}
