#include <iostream>
#include <windows.h>
#include <iomanip>
#include <cmath>

using namespace std;
double y(double x){
    if (-2 <= x && x <= 0){
        return 2 + 4 * x;
    } else if (0 < x && x <= 2){
        return 2 - 4 * x;
    } else {
        return pow(x, 2) - 10;
    }

}
int main (){
    double a = 3.5;
    cout << y(a);

    return 0;
}
