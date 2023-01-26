#include <iostream>
#include <windows.h>
#include <ctime>
#include <iomanip>

using namespace std;

int main()
{
    srand(time(NULL));
    int arr[10];
    int ans[10];

    for (int i=0;i<10;i++)
    {
        arr[i]=rand()%40-20;
        cout<<setw(4)<<arr[i];
    }

    cout<<endl;
    int j=0;
    int key;
    cin>>key;
    cout<<endl;

    for (int i=0;i<10;i++)
        if (arr[i]==key)
        {
           ans[j++]=i;
        }
    cout<<endl;
    if (j!=0)
    {
        for (int i=0;i<j;i++)
        {
            cout<<setw(4)<<ans[i];
        }
    }
    else
    {
        cout<<"key not found";
    }

    return 0;
}
