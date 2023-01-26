#include<iostream>
#include<cmath>
#include<windows.h>
#include<iomanip>
int main()
{
    using namespace std;
    SetConsoleOutputCP (1251);
    SetConsoleCP (1251);
    double r,t,s,n,x,i;

    cout<<" введите n=";
    cin>>n;
    cout<<" введите x=";
    for (i=1;i<=n;i++)
    {
        cin>>x;
        if (x<=1)
            r=r+x;
        else
            s=s+x;
        t=(1+r);//(1+s);
    }


    cout<<"t="<<fixed<<setprecision(2)<<t<<endl;


}
