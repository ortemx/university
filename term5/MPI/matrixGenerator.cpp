 #include <iostream>
#include <ctime>
#include <iomanip>
#include <stdlib.h>
#include <fstream>
#include <windows.h>

using namespace std;


template <typename T>
void generateMatrix(T A, int m, int n){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            A[i][j] = rand() % 40 - 20;
        }
    }
}


template <typename T>
void generateVector(T V, int n){
    for (int i = 0; i < n; i++){
        V[i] = rand() % 40 - 20;
    }
}


template <typename T>
void recordMatrix(T** A, int m, int n){
    ofstream out ("A.txt");
    out << m << "\n";
    out << n << "\n";

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            out << A[i][j] << "\n";
        }
    }

    out.close();
}


template <typename T>
void recordVector(T* A, int n){
    ofstream out ("b.txt");
    out << n << "\n";

    for (int i = 0; i < n; i++){
        out << A[i] << "\n";
    }

    out.close();
}


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
void printVector(T A, int n, string mode = "column"){
    for (int i = 0; i < n; i++){
        cout << setw(4) << A[i];
        if (mode == "column"){
            cout<<endl;
        }
    }
}


int main(){
    setlocale(0,"Russian");
    srand(time(NULL));


    int n = 500;

    int **A = new int *[n];
    int *V = new int[n];

    for(int i = 0; i < n; i++){
        A[i] = new int[n];
    }

    generateMatrix(A, n, n);
    recordMatrix(A, n, n);

    generateVector(V, n);
    recordVector(V, n);
    return 0;
}
