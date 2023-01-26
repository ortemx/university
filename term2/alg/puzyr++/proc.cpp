#include <iostream>
#include <algorithm>
#include <windows.h>
#include <ctime>
#include <iomanip>
#include <sstream>
#import "ctime"
using namespace std;

double number(string str){
    stringstream f;
    f << str;
    double n;
    f >> n;
    return n;
}

void booble_sort(int *arr, int n)
{
    bool flag = false;
    for (int i=0;i<n;i++)
    {
        flag = true;
        for (int j=0; j<n-1;j++)
        {
            if (arr[j]>arr[j+1])
            {
                flag = false;
                swap(arr[j],arr[j+1]);
            }
        }
    if (flag)
        break;
    }
}
int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(NULL));

    int n; cin>>n;
    int *arr = new int [n];

    for (int i = 0; i < n; i++) {
        arr[i]=rand()%40-20;
        cout<<setw(4)<<arr[i];
    }

    booble_sort(arr, n);

    cout<<endl;
    for (int i = 0; i < n; i++)
        cout<<setw(4)<<arr[i];
    cout<< "\n" << number("12");
return 0;
}
