#include <iostream>
#include <windows.h>
#include <iomanip>
#include <ctime>
#include <cmath>

using namespace std;

int main (){
    //srand(time(NULL));

    long double a,b, x, d, s;
    cout<<"enter a "; cin>>a;
    cout<<"enter b "; cin>>b;
    cout<<"enter x "; cin>>x;
    //x = 0;
    //a = 18;
    //b = 9;
    d = pow(x, 3) * pow( tan( pow(x + b, 2) ), 2) + a / pow (x + b, 0.5);
    s = (b * x * x - a )/(exp(a*x)+1);

    cout<<fixed<<setprecision(10)<<"d = "<<d<<endl;
    cout<<fixed<<setprecision(10)<<"s = "<<s;



    return 0;
}
