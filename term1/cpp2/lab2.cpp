#include<iostream>
#include<cmath>
#include<windows.h>
#include<iomanip>
int main()
{
    using namespace std;
    SetConsoleOutputCP (1251);
    SetConsoleCP (1251);
    double i,s,n,p,x;

    cout<<" ������� n=";
    cin>>n;
    cout<<" ������� x=";
    cin>>x;
    p=sin(x);
    s=p;
    for (i=1;i<=n;i++)
    {
        p=sin(p);
        s=s+p;
    }

    cout<<"s="<<fixed<<setprecision(2)<<s<<endl;


}
