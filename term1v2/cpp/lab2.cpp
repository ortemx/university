#include <iostream>
#include <iomanip>
#include <windows.h>
#include <ctime>

using namespace std;


int main(){

    double a = 2;
    int n = 5;
    double p = a;
    double s = 1/p;
    cout<<p<<" "<<s<<endl;
    for (int i = 1; i <= n; i++){
        p *= a + i;
        s += 1 / p;
        cout<<p<<" "<<s<<endl;
    }


return 0;
}
