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

void sum(int *a, int*b, int *s, int ss)
{
    for (int i=0;i<ss ;i++)
        s[i]=0;

    for (int i=0;i<ss ;i++)
        {
            s[i]+=(a[i]+b[i]);
            if (s[i]>9){
                s[i+1]++;
            }
            s[i]%=10;
        }
}
int main()
{
    srand(time(NULL));

    int k1,k2;
    cout<<"vveditr kol-vo cifr 1 chisla"<<endl;
    cin>>k1;
    cout<<"vveditr kol-vo cifr 2 chisla"<<endl;
    cin>>k2;
    int l=max(k1,k2)+1;
    int*a = new int[k1];
    int*b = new int[k2];
    int*s = new int[l];

    chislo(a,k1);
    print(a,k1);

    chislo(b,k2);
    print(b,k2);

    sum(a,b,s,l);
    print(s,l);

return 0;
}
