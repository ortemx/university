#include <iostream>
#include <sstream>
#include <iomanip>
#include <cmath>
using namespace std;

int len(double a){
    stringstream stream ;
    string str;
    stream << floor(a);
    stream >> str;
    return str.length();
}

int main(){
/*
123456789
     99.26664511
  -9245.98
-917817.4153542
*/

    double a;
    double b;
    //cin >> a;
    //cin >> b;
    a = 99.26664511;
    b = -9245.98;
    cout << (double)a * b;
    //cout << setw(len(a) + len(b)) << a << "\n";
    //cout << setw(len(a) + len(b)) << b;

    return 0;
}
