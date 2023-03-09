#include <iostream>
#include <windows.h>
#include <iomanip>
#include <ctime>

using namespace std;

int main (){
    int n;
    double a;

    cout << "enter n "; cin >> n;
    cout << "enter a "; cin >> a;

    double p = 1;
    double s = 0;

    for (int i = 0; i <= n;  i++){
        p *= (a + i);
        s += 1 / p;
    }

    cout << "s = " << s;
    return 0;
}
