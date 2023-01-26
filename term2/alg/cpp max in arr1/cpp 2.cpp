#include <iostream>
#include <algorithm>


using namespace std;

void MaxEl(int arr[], int Size)
{
     sort(arr, arr+Size);
     cout<<arr[Size-1];
}
int main ()
{
    int n = 10;
    int mas[n] = { -5, 1, 4, 3, 165, 5, 6, 9, 10, 9 };

    MaxEl(mas, n);
return 0;
}

