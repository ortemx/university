#include <iostream>
#include <iomanip>
#include <windows.h>
#include <ctime>

using namespace std;

void koef(int a, int mas[])
{
     for (int i=0;i<=a;i++){
        cout<<endl<<"vvedite k "<<i<<" stepeni"<<endl;
        cin>>mas[i];
    }
}

void print(int l,int k3[])
{
    cout<<endl<<k3[0]<<"x^0";
    for (int i=1;i<=l;i++)
        cout<<"+"<<k3[i]<<"x^"<<i;
}

void sum(int a1,int a2, int k1[],int k2[], int k3[])
{
    koef(a1, k1);
    print(a1, k1);

    koef(a2, k2);
    print(a2, k2);

    int l = max(a1,a2);

    for (int i=0;i<=l;i++)
        k3[i]=k1[i]+k2[i];
}

int main()
{
    int a1,a2;
    cout<<"vvedite starshie stepeni"<<endl;
    cin>>a1>>a2;

    int l = max(a1,a2);

    int *k1= new int[a1+1];
    int *k2= new int[a2+1];
    int *k3 = new int [l+1];

    sum(a1,a2,k1,k2,k3);

    print(l,k3);
    delete[]k1;
    delete[]k2;
    delete[]k3;
return 0;
}
