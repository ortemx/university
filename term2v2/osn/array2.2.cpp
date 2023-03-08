#include <iostream>
#include <windows.h>
#include <ctime>
#include <iomanip>
using namespace std;

int *Array(int *X, int n, int *Y, int m){
    int number_positive = 0;
    for(int i = 0; i < n; i++){
        if (X[i] > 0)
        number_positive++;
    }
    for(int i = 0; i < m; i++){
        if (Y[i] > 0)
        number_positive++;
    }
    cout << "\npos = " << number_positive << endl;
    int * Array = new int [number_positive];
    int index = 0;
    for(int i = 0; i < n; i++){
        if (X[i] > 0)
            Array[index++] = X[i];
    }
    for(int i = 0; i < m; i++){
        if (Y[i] > 0)
            Array[index++] = Y[i];
    }
    for(int i = 0; i < number_positive; i++){
        cout << setw(4) << Array[i];
    }
    return Array;
}

int main(){
    srand(time(NULL));
    int n = 10;
    int m = 16;
    int *X = new int[n];
    int *Y = new int[m];
    cout << "X : ";
    for(int i = 0; i < n; i++){
        X[i] = rand() % 20 - 10;
        cout << setw(4) << X[i];
    }
    cout << "\nY : ";
    for(int i = 0; i < m; i++){
        Y[i] = rand() % 20 - 10;
        cout << setw(4) << Y[i];
    }
    int *Z = Array(X, n, Y, m);

    return 0;
}
