#include <iostream>
#include <algorithm>
#include <windows.h>
#include <ctime>
#include <iomanip>

using namespace std;
int binsearch(int* Arr, int s, int n, int l=0){
    int m=(l+n)/2;
    if (Arr[m] == s) return m;
    if (m == l || m == n) return -1;
    if (Arr[m] < s) binsearch(Arr, s, n, m);
    else  binsearch(Arr, s, m);
    }

int main()
{
    int key;
    int arr[10];
    for (int i = 0; i < 10; i++)
    {
        arr[i]=rand()%40-20;
    }

    for (int i = 0; i < 10; i++)
    {
        cout<<setw(4)<<arr[i];
    }
    cout<<endl;


    sort (arr, arr + 10);

    for (int i = 0; i < 10; i++)
    {
        cout<<setw(4)<<arr[i];
    }
    cout<<endl;
    cin >> key;
    cout<<"index ="<<binsearch(arr, key, 9, 0);
    return 0;
}


