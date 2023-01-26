#include  <iostream>
#include <windows.h>
#include <iomanip>
#include <ctime>

using namespace std;

int  quick(int *arr, int start, int end1)
{
    int pivot = arr[end1];
    int partitionindex = start;
    for (int i=start;i<end1;i++)
    {
        if (arr[i]<=pivot)
        {
            swap(arr[i],arr[partitionindex]);
            partitionindex++;
        }
    }
    swap(arr[partitionindex],arr[end1]);
    return partitionindex;
}

void sor(int *arr, int start, int end1)
{
    if (start<end1)
    {
        int partitionindex = quick(arr,start,end1);
        sor(arr, start,partitionindex-1);
        sor(arr,partitionindex+1,end1);
    }
}

int main ()
{
    srand(time(NULL));
    int n = 100000;
    int arr[n];
    int end1 =n-1, start=0;
    for (int i=0;i<n;i++)
    {
        arr[i]=rand()%40-20;
        //cout<<setw(4)<<arr[i];
    }
    sor(arr,  start, end1 );
    cout<<endl;
    for (int i=0;i<n;i++)
    {
        //cout<<setw(4)<<arr[i];
    }

    return 0;
}
