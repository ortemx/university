#include <iostream>
#include <vector>
#include <windows.h>
#include <ctime>
#include <iomanip>
using namespace std;

void Array(vector <int> &V, int *A, int n){
    for (int i = 0; i < n; i++){
        if (A[i] > 0)
            V.push_back(A[i]);
    }
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
    vector <int> Z;
    Array(Z, X, n);
    Array(Z, Y, m);
    cout << "\nZ : ";
    for (int i = 0; i < Z.size(); i++){
        cout << setw(4) << Z[i];
    }
    return 0;
}
