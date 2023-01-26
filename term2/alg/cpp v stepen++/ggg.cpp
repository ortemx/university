#include <iostream>
#include <windows.h>

using namespace std;
double Power(double a, int n){
    double S = 1;
    double k =a;
    while (n > 0) {
        if (n % 2 == 1)
            S *= k;
        k *=k;
        n /=2;
    }
return S;
}
int main () {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    double a;
    int n;
    cout<<"¬ведите число :"<<" ";
    cin>>a;
    cout<<"¬ведите степень :"<<" ";
    cin>>n;
    cout<<Power(a,n);
    return 0;


}
