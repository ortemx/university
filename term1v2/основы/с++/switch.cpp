#include <iostream>
#include <iomanip>
#include <windows.h>
#include <ctime>

using namespace std;


int main(){
    double a = 4;
    double b = 0;
    double k = 1;
    double c;
    int remainder;
    c = k *(a+b);
    remainder = (int)c % 4;
    cout << "c = " << c << " remainder = " <<remainder;

    switch (remainder){
        case 1:
        case 3:
            c -= remainder;
            break;
        case 2:
            c += remainder;
    }
    cout << "\nc(new) = " << c;
return 0;
}
