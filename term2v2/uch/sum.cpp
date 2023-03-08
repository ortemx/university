#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(){
    double s;
    double eps = 0.0001;
    double x;
    double a;
    double y;
    cout << "   x    sum    f(x)" << endl;
    for (double x = 0.1; x <= 1; x += 0.09 ){
        s = 0;
        a = 1;
        for (int i = 1; a > eps; i++){
            s += a;
            a *= x * x / ((2*i-1)*2*i);
        }
        y  = (exp(x)+exp(-x))/2;
        cout << setw(6) << x << "  " << s << "  " << y << " " <<abs(s - y) <<endl;
    }

return 0;
}
