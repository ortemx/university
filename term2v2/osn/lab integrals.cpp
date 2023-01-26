#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

float f(float x){
    return pow (x, x) * (1 + log(x));
}

float F(float x){
    return pow (x, x);
}

float pryam(int a, int b, float eps, float f(float), int &k){
    int n = 1;
    float I1, h, x;
    float I2 = (b - a) * f((a + b) / 2);
    k = 1;
    do {
        n *= 2;
        I1 = I2;
        I2 = 0;
        h = float (b - a) / n;
        for(x = a; x < b; x += h){
            I2 += f(x);
        }
        I2 *= h;
        k++;
    }
    while (abs(I2 - I1) >= eps);
    return I2;
}

float trap(int a, int b, float eps, float f(float), int &k){
    int n = 1;
    float I1, h, x;
    float I2 = (b - a) * f((a + b) / 2);
    k = 1;
    do {
        n *= 2;
        I1 = I2;
        I2 = (f(a) + f(b)) / 2;
        h = float (b - a) / n;
        for(x = a+h; x < b; x+=h){
            I2 += f(x);
        }
        I2 *= h;
        k++;
    }
    while (abs(I2 - I1) >= eps);
    return I2;
}

float simpson(int a, int b, float eps, float f(float), int &k){
    int n = 1;
    float I1, h, x;
    float I2 = (b - a) * f((a + b) / 2);
    float S1, S2;
    k = 1;
    do {
        n *= 2;
        I1 = I2;
        I2 = f(a) + f(b);
        h = float (b - a) / (2 * n);
        S1 = S2 = 0;
        x = a + h;
        for(int i = 2; i <= 2 * n - 2; i += 2){
            S2 += f(x);
            x += h;
            S1 += f(x);
            x += h;
        }
        S2 += f(a + (2 * n - 1) * h);
        I2 = h *(I2 + 2 * S1 + 4 * S2) / 3;
        k++;
    }
    while (abs(I2 - I1) >= eps);
    return I2;
}

int main(){
    const int a = 1, b = 3;
    const float eps = 0.0001;
    int k, choice ;
    do {
        system("CLS");
        cout << "1. Metod pryamougol'nikov\n";
        cout << "2. Metod trapecii\n";
        cout << "3. Metod Simpsona\n";
        cout << "0. Vyhod\n";
        cin >> choice;
        switch (choice){
            case 1:
                cout << pryam(a, b, eps, f, k);
                cout << "   n=" << k << endl;
                cout << "Tochnoe znachenie: " << F(b) - F(a) << endl;
                break;
            case 2:
                cout << trap(a, b, eps, f, k);
                cout << "   n=" << k << endl;
                cout << "Tochnoe znachenie: " << F(b) - F(a) << endl;
                break;
            case 3:
                cout << simpson(a, b, eps, f, k);
                cout << "   n=" << k << endl;
                cout << "Tochnoe znachenie: " << F(b) - F(a) << endl;
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




