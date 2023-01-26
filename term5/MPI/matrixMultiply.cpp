 #include <iostream>
#include <ctime>
#include <iomanip>
#include <stdlib.h>
#include <fstream>
#include <windows.h>

using namespace std;


template <typename T>
void generateMatrix(T** A, int m, int n){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            A[i][j] = rand() % 40 - 20;
        }
    }
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
T** matrixMultiply(T **A, T **B, int m, int k, int n){

    T** C = new T* [m];
    for (int i = 0; i < m; i++){
        C[i] = new T[n];
        for (int j = 0; j < n; j++){
            C[i][j] = 0;
            for (int p = 0; p < k; p++){
                C[i][j] += A[i][p] * B[p][j];
            }
        }
    }

    return C;
};


void matrixAddition(int **A, int **B, int m, int n){
    cout << "\nC:\n";
    int temp = 0;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            temp =  A[i][j] + B[i][j];
            cout << temp << " ";
        }
        cout << "\n";
    }
};


int main(){
    setlocale(0,"Russian");
    srand(time(NULL));


    double PCFreq, time;
    __int64 start = 0;
    __int64 finish = 0;
    LARGE_INTEGER li;

    ofstream out;

    int m = 10;
    int n = 100;
    int k = 10;

    int **A = new int *[m];

    for(int i = 0; i < m; i++){
        A[i] = new int[n];
    }

    int **B = new int *[n];
    for(int i = 0; i < n; i++){
        B[i] = new int[k];
    }

    int **MultiplyResult = new int *[m];

    for (int i = 0; i < m; i++){
        MultiplyResult[i] = new int[n];
    }

    generateMatrix(A, m, n);
    //printMatrix(A, m, n);

    cout << endl;

    generateMatrix(B, n, k);
    //printMatrix(B, n, k);


    QueryPerformanceFrequency(&li);
    PCFreq = (double)(li.QuadPart) / 1000.0;

    QueryPerformanceCounter(&li);
    start = li.QuadPart;

    MultiplyResult = matrixMultiply(A, B, m, n, k);

    QueryPerformanceCounter(&li);
    finish = li.QuadPart;

    time = (double)(finish - start) / PCFreq;
    cout << "\nвремя: " << time << "ms\n";

    out.open("resultForMultiply.txt", ios::app);

    out << setw(8) << m << setw(8) << k << setw(8) << n << setw(8) << time << "ms\n";


    cout << endl;
    //printMatrix(MultiplyResult, m, n);
    out.close();
    return 0;
}
