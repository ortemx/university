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
T** matrixAddition(T **A, T **B, int m, int n){
    T** C = new T* [m];
    for (int i = 0; i < m; i++){
        C[i] = new T[n];
        for (int j = 0; j < n; j++){
            C[i][j] =  A[i][j] + B[i][j];
        }
    }

    return C;
};


int main(){
    setlocale(0,"Russian");
    srand(time(NULL));


    double PCFreq, time;
    __int64 start = 0;
    __int64 finish = 0;
    LARGE_INTEGER li;

    ofstream out;

    int m = 900;
    int n = 900;

    int **A = new int *[m];
    int **B = new int *[m];
    int **AdditionResult = new int *[m];

    for(int i = 0; i < m; i++){
        A[i] = new int[n];
        B[i] = new int[n];
        AdditionResult[i] = new int[n];
    }

    generateMatrix(A, m, n);
    //printMatrix(A, m, n);

    cout << endl;

    generateMatrix(B, m, n);
    //printMatrix(B, n, n);


    QueryPerformanceFrequency(&li);
    PCFreq = (double)(li.QuadPart) / 1000.0;

    QueryPerformanceCounter(&li);
    start = li.QuadPart;

    AdditionResult = matrixAddition(A, B, m, n);

    QueryPerformanceCounter(&li);
    finish = li.QuadPart;

    time = (double)(finish - start) / PCFreq;
    cout << "\nвремя: " << time << "ms\n";

    out.open("resultForAddition.txt", ios::app);

    out << setw(8) << m << setw(8) << n << setw(8) << time << "ms\n";

    //printMatrix(AdditionResult, m, n);
    out.close();
    return 0;
}
