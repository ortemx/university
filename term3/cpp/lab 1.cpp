#include <iostream>
#include <iomanip>
#include <windows.h>
#include <ctime>
#include <cmath>
using namespace std;

int main()
{
    double x = 0.1;
    double eps = 0.001;

    for ( int i=0; x<=1; i++){
        double a = (-1)*(pow(x,2))/2;
        double s = 1;
        int n = 1;

        do {
            s+=a;
            double y = (-1)*(pow(x,2))/((2*n+1)*(2*n+2));
            a*=y;
            n++;
        } while (abs(a)>=eps);
        cout<<setw(4)<<x<<setw(8)<<s
        <<setw(8)<<setprecision(5)<<cos(x)
        <<setw(8)<<setprecision(3)<<fixed<<abs(s-cos(x))<<endl;
        x+=0.09;
    }

return 0;
}
