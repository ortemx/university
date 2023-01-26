#include <iostream>
#include <windows.h>


using namespace std;

double Power(double a, int n){
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

int main (){
    setlocale(LC_ALL, "rus");

    double a;
    int n;
    cout<<"¬ведите число :"<<" ";
    cin>>a;
    cout<<"¬ведите степень :"<<" ";
    cin>>n;
    cout<<Power(a,n);

return 0;
}

