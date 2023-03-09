#include <iostream>
#include <windows.h>
#include <iomanip>
#include <cmath>

using namespace std;

int main (){

    double R;
    double x0, y0;

    cout << "enter x0: "; cin >> x0;
    cout << "enter y0: "; cin >> y0;
    cout << "enter R: "; cin >> R;

    if ( ((x0*x0 + y0*y0 <= R*R) || !(abs (x0 - R) >= R || (abs (y0 - R) >= R))) &&
         !((x0*x0 + y0*y0 <= R*R) && !(abs (x0 - R) >= R || (abs (y0 - R) >= R)))  ){
        cout << "+";

    } else {
        cout << "-";
    }

    return 0;
}
