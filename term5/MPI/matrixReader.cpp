 #include <iostream>
#include <ctime>
#include <iomanip>
#include <stdlib.h>
#include <fstream>
#include <windows.h>

using namespace std;

template <typename T>
void printMatrix(T A, int m, int n){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cout << setw(11) << A[i][j];
        }
        cout<<endl;
    }
}


template <typename T>
void readMatrix(T A, int m, int n, ifstream *in){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            *in >> A[i][j];
        }
    }
}


template <typename T>
void readVector(T A, int n, ifstream *in){
    for (int i = 0; i < m; i++){
        *in >> A[i];
    }
}



int main(){
    setlocale(0,"Russian");
    srand(time(NULL));

    int n;

    ifstream in("A.txt");

    in >> n;
    in >> n;

    int **A = new int* [n];
    for(int i = 0; i < n ; i++){
        A[i] = new int[n];
    }

    readMatrix(A, n, n, &in);
    printMatrix(A, n, n);

    return 0;
}
