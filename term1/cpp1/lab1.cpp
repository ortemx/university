#include<iostream>
#include<cmath>
#include<windows.h>
#include<iomanip>
int main()
{
    using namespace std;
    setlocale(LC_ALL, "rus");
    double a,b,x,f,v;
    cout<<" введите a=";
    cin>>a;
    cout<<" введите b=";
    cin>>b;
    cout<<" введите x=";
    cin>>x;
    v=(pow(a,2)*x+exp(-x)*cos(b*x))/(b*x-exp(-x)*sin(b*x)+1);
    f=exp(2*x)*log(a+x)-pow(b,3*x)*log(b-x);
    cout<<"v= "<<fixed<<setw(10)<<v<<endl;
    cout<<"f= "<<fixed<<setw(10)<<f<<endl;


}
