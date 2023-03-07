#include<iostream>
#include<cmath>
// #include<windows.h>
#include<iomanip>
int main()
{
    using namespace std;
    // SetConsoleOutputCP (1251);
    // SetConsoleCP (1251);
    double i, s, n, p, x;

    printf("Введите n: ");
    cin >> n;
    printf("Введите x: ");
    cin >> x;
    p = sin(x);
    s = p;
    for (i = 1; i <= n; i++) {
        p = sin(p);
        s = s + p;
    }

    printf("s = %.2f\n", s);
}
