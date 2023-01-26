#include <iostream>
#include <windows.h>
#include <cmath>

using namespace std;

double p(double a, int n){
    double p=1;
    double b=a;
    int k=n;
    while (k > 0) {
        if (k % 2 == 0) {
           k=k/2;
           b=b*b;
        }

        if (k % 2 == 1) {
            k--;
            p=p*b;
        }
    }
    return p;
}

double power(int a, int n){
    if (n == 0){
        return 1;
    }
    double x = power (a, n/2);
    if ( n % 2 == 0)
        return pow (x, 2);
    else
        return (a * pow(x,2));

}

int main ()
{
    setlocale(LC_ALL, "rus");

    double a;
    int n;
//    cout<<"¬ведите число :"<<" ";
//    cin>>a;
//    cout<<"¬ведите степень :"<<" ";
//    cin>>n;
//    cout<<p(a,n);
    for (int i = 0; i < 10000000; i++){
        //n = p(9,24);
        //n = pow(9,24);
        n = power (9, 24);
    }
    //cout<<pow(5,5);

    return 0;
}

