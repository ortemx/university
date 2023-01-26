#include <iostream>
#include <cmath>
#include <cstdlib>
#include <windows.h>
#include <tlhelp32.h>
#include <ctime>
#include <iomanip>
#include <fstream>

using namespace std;


template <typename T>
void printVector(T A, int n, string mode = "column"){
    for (int i = 0; i < n; i++){
        cout << setw(4) << A[i];
        if (mode == "column"){
            cout<<endl;
        }
    }
}


template <typename T>
void multiplyByVector(T **A, T *X, T *B, int m, int n){
    for (int i = 0; i < m; i++){
        B[i] = 0;
        for (int j = 0; j < n; j++){
            B[i] += A[i][j] * X[j];
        }
    }
};


int main()
{
    setlocale(0,"Russian");
    srand(time( NULL));


    double *x, *b, *C;
    ifstream streamReader;
    ofstream streamWriter;
    int m, n = NULL;


    // ���������� ������� x �� �����

    streamReader.open("X.txt");
    streamReader >> n;

    x = new double[n];
    for(int i = 0; i < n; i++){
        streamReader >> x[i];
    }

    streamReader.close();

    //printVector(x, n);


    // ���������� ������� b �� �����

    streamReader.open("B.txt");
    streamReader >> n;

    b = new double[n];
    for(int i = 0; i < n; i++){
        streamReader >> b[i];
    }

    streamReader.close();

    //printVector(b, n);


    // ���������� ������� � �� �����

    streamReader.open("A.txt");
    streamReader >> m;
    streamReader >> n;

    double **A = new double * [m];

    for(int i = 0; i < m; i++){
        A[i] = new double [n];
        for(int j = 0; j < n; j++){
            streamReader >> A[i][j];
        }
    }

    streamReader.close();


    // ��������� ������ �� ������ � = ��

    C = new double[n];


    // ������������ ������� � �� ������ �

    multiplyByVector(A, x, C, m, n);

    //printVector(C, n);


    // �������� ������� � - b = 0

    double c = 0;
    for(int i = 0; i < n; i++){
        if (C[i] - b[i] < 0.00001){
            cout << setprecision(16) << C[i] - b[i] << "\n";
        }
        c += abs(C[i] - b[i]);
    }

    cout << "\nc = " << c / n;

    return 0;
}
