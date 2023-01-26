#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

float f(float x) {
    //return 0.1*x*x-x*log(x);
    return 3*x - 14 + exp(x) - exp(-x) ;
}
float df (float x) {
    //return -1 + 0.2 * x - log(x);
    return 3+ exp(x) + exp(-x);
}
float ddf(float x){
    //return 0.2 - 1/x;
    return exp(x) - exp(-x);
}

float half_division_method(float a, float b, float  eps, int k){
    float c;
    while (b - a > eps){
        c = (a + b)/2;
        if (f(c)* f(a) < 0){
            b = c;
        } else {
            a = c;
        }
        k++;
    }
    cout << "k = "<< k << endl;
    return c;
}

float chord_method(float a, float b, float  eps, int k){
    double x1 = a - f(a)*(b-a) / (f(b)-f(a));

    while(f(x1) > eps){
        if (f(x1)*f(b) < 0) {
            x1  = x1 - f(x1)*(b-x1) / (f(b)-f(x1));
        }
        k++;
    };
    cout << "k = "<< k << endl;
    return x1;
}

float tangent_method(float a, float b, float  eps, int k){
// http://mathprofi.ru/metod_kasatelnyh.html
    double x;
    if (f(a)*ddf(a) > 0){
        x = a;
    } else {
        x = b;
    }
    while(abs(f(x)/df(x)) > eps){
        cin >> a;
        cout << "\n" <<x;
        x = x - f(x)/df(x);
        k++;
    }
    cout << "k = "<< k << endl;
    return x;
}

int main(){
    float a = 0.5, b = 1.5;
    a = 1.5;
    b = 2.5;
    float eps = 0.0001;
    int k(0), choice ;
    do {
        system("CLS");
        cout << "1. half_division_method\n";
        cout << "2. chord_method\n";
        cout << "3. tangent_method\n";
        cout << "0. Vyhod\n";
        cin >> choice;
        switch (choice){
            case 1:
                cout << half_division_method(a, b, eps, k);
                break;
            case 2:
                cout << chord_method(a, b, eps, k);
                break;
            case 3:
                cout << tangent_method(a, b, eps, k);
                break;
            case 0:
                break;
            default:
                continue;
        }
        system("pause");
    }
    while (choice != 0);
    return 0;
}




