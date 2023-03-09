#include <iostream>
#include <cmath>
#include <windows.h>
#include <iomanip>
#define PI 3.14159265
using namespace std;

int main(){

    double a = 1;
    double b = 2 * PI / 180;
    double x = -1 * PI / 180;

    double d = pow(x, 3) * pow(tan(pow(x+b,2)),2)+(double)a/sqrt(x+b);
    double s = (pow(b*x, 2)- a)/(exp(a*x)+1);

    cout<<"d="<<fixed<<setprecision(2)<<d<<endl;
    cout<<"s="<<fixed<<setprecision(2)<<s<<endl;


return 0;
}
