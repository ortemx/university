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
        double a = x;
        double s = 0;
        int n = 0;

        do {
            s+=a;
            double y = (pow(x,2))/((2*n+2)*(2*n+3));
            a*=y;
            n++;
        } while (abs(a)>=eps);
        cout<<setw(4)<<x<<setw(8)<<s
        <<setw(8)<<setprecision(5)<<(exp(x)-exp(-x))/2
        <<setw(8)<<setprecision(3)<<fixed<<endl;
        x+=0.09;
    }

return 0;
}
