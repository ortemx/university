#include <iostream>
#include <iomanip>
#include <windows.h>
#include <cmath>

using namespace std;


int main(){
    double x0 = 0;
    double y0 = 5;
    double r = 2;
    double k = 0;
    double b = 3;
    double x, y;
    double A ,B, C, d;
    double a1, b1, c1, d1, x1, x2, y1, y2;
    A = k;
    B = -1;
    C = b;

    d = abs((A*x0+B*y0+C)/(pow(A*A+B*B, (double)0.5)));
    if (d > r){
        cout << " - ";
    } else if (d == r){
        a1 = 1 + A*A/(B*B);
        b1 = -2*x0+2*C*A/(B*B)+2*A*y0/B;
        //========================
        if (k == 0){
            x = b1/(2*a1);
        } else{
            x = -b1/(2*a1);
        }
        //========================
        y = (-C-A*x)/B;
        cout << "x = "<< x << " y = " << y;
    } else {
        a1 = 1 + A*A/(B*B);
        b1 = -2*x0+2*C*A/(B*B)+2*A*y0/B;
        c1 = x0*x0+C*C/(B*B) + 2*C*y0/B+y0*y0-r*r;
        d1 = b1*b1 - 4 * a1 * c1;
        x1 = (-b1+pow(d1, 0.5))/(2*a1);
        x2 = (-b1-pow(d1, 0.5))/(2*a1);
        y1 = (-C-A*x1)/B;
        y2 = (-C-A*x2)/B;
        cout << "x1 = " << x1 << " y1 = " << y1 << "\nx2 = "<<  x2 << " y2 = " << y2;
    }

return 0;
}
