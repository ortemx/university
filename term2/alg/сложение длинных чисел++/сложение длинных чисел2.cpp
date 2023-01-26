#include <iostream>
#include <iomanip>
#include <windows.h>
#include <ctime>

using namespace std;

void chislo(int *a, int l)
{
    for (int i=0; i<l; i++)
        a[i]=rand()%9;
}

void print(int *a, int l)
{
    for (int i=0;i<l ;i++)
        cout<<a[i];
    cout<<endl;
}

void sum(int *a, int*b, int k1, int k2)
{
    int l=max(k1,k2)+1;
    int *s = new int [l];

    for (int i=0;i<l ;i++)
        s[i]=0;

    for (int i=k1-k2, j=0; i<k1, j<k2; j++,i++)
    {
        s[i]+=(a[i]+b[j]);
        if (s[i]>9){
            s[i]-=10;
            s[i-1]++;
        }
    }

    cout<<endl;
    for (int i=0;i<l ;i++)
        cout<<s[i];
}
int main()
{
    //srand(time(NULL));

    int k1=5,k2=4;
    cout<<"vveditr kol-vo cifr 1 chisla"<<endl;
    //cin>>k1;
    cout<<"vveditr kol-vo cifr 2 chisla"<<endl;
    //cin>>k2;
    if (k2>k1)
        swap(k1,k2);
    int*a = new int[k1];
    int*b = new int[k2];

    chislo(a,k1);
    print(a,k1);

    chislo(b,k2);
    print(b,k2);

    sum(a,b,k1,k2);







return 0;
}
