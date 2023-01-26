#include  <iostream>
#include <windows.h>
#include <iomanip>
#include <ctime>

using namespace std;

void qsort(int *arr, int first, int last)
{
    int f=first;
    int l=last;
    int mid=arr[(f+l)/2];
    while (f<=l)
    {
        while (arr[f]<mid)
            f++;
        while (arr[l]>mid)
            l--;
        if (f<=l) {
            swap(arr[f],arr[l]);
            f++;
            l--;
        }
    }
    if (first<l)
        qsort(arr, first, l);
    if (f < last)
        qsort(arr, f, last);
}

int main()
{
    srand(time(NULL));
    int n=10;

    int *arr = new int [n];

    int last =n-1, left=0;
    for (int i=0;i<n;i++){
        arr[i]=rand()%40-20;
        cout<<setw(4)<<arr[i];
    }

    qsort(arr, left, last );

    cout<<endl;
    for (int i=0;i<n;i++)
        cout<<setw(4)<<arr[i];

    return 0;
}
