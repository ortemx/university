#include <iostream>
#include <iomanip>
#include <windows.h>
#include <ctime>

using namespace std;


int main(){
    double a = 6;
    double b = 6;
    double k = 1;
    double c;
    int remainder;
    c = k*(a+b);
    remainder = (int)c % 4;
    cout << "c = " << c << " remainder = " <<remainder;

    switch (remainder){
        case 1 :
            c -= remainder;
            break;
        case 2:
            c += remainder;
            break;
        case 3:
            c -= remainder;
            break;
    }
    cout << "\nc(new) = " << c;
return 0;
}
