#include<iostream>
#include<cmath>
// #include<windows.h>
#include<iomanip>
using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    double a, b, x, f, v;
    printf("Введите a: ");
    cin >> a;
    cout << "Введите b: ";
    cin >> b;
    cout << "Введите x: ";
    cin >> x;
    v = (pow(a, 2) * x + exp(-x) * cos(b * x)) / ( b * x - exp(-x) * sin(b * x) + 1);
    f = exp(2 * x) * log(a + x) - pow(b, 3 * x) * log(b - x);

    printf("v = %015.10f\nf = %15.10f", v, f);
    //cout << "v= " << fixed << setw(10) << v << endl;
    //cout << "f= " << fixed << setw(10) << f << endl;


}
