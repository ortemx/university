#include <iostream>
#include <windows.h>
#include <ctime>
#include <iomanip>
using namespace std;

int number_positive(int **A, int n, int m){
    int s = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (A[i][j] > 0)
                s += A[i][j];
        }
    }
    return s;
}
int main(){
    srand(time(NULL));
    int n = 10;
    int m = 14;
    int r = 15;
    int t = 6;
    int **X = new int * [n];
    for (int i = 0; i < n; i++){
        X[i] = new int[m];
    }
    int **Y = new int * [r];
    for (int i = 0; i < r; i++){
        Y[i] = new int[t];
    }
    cout << "X\n";
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            X[i][j] = rand() % 20 - 10;
            cout << setw(4) << X[i][j];
        }
        cout <<endl;
    }
    cout << "Y\n";
    for (int i = 0; i < r; i++){
        for (int j = 0; j < t; j++){
            Y[i][j] = rand() % 20 - 10;
            cout << setw(4) << Y[i][j];
        }
        cout <<endl;
    }
    cout << "sum positive in X: " << number_positive(X, n, m);
    cout << "\nsum positive in Y: " << number_positive(Y, r, t);
    return 0;
}
