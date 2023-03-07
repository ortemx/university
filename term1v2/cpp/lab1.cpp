#include <iostream>
#include <iomanip>
// #include <windows.h>
#include <ctime>
#include <cmath>

#define PI 3.14159265358979323846

using namespace std;

int main(){
    double a = 1;
    double b = 2;
    double x = 3;

    double d = pow(x, 3) * pow(tan(pow((x + b), 2) * PI / 180), 2) + (a) / sqrt(x + b);
    double s = (b * x * x - a) / (exp(a * x) + 1);

    printf("d = %.10f\ns = %.10f\n", d, s);

    return 0;
}
