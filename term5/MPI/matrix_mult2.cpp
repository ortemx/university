#include <iostream>
#include <ctime>
#include <iomanip>
#include <stdlib.h>
#include <fstream>

using namespace std;


void first_matrix_generator(int **A, int m, int k){

    cout << "A:\n";
    for (int i = 0; i < m; i++){
        for (int j = 0; j < k; j++){
            A[i][j] = rand() % 41 - 20;
            cout << A[i][j] << " ";
        }
         cout << "\n";
    }
}


void second_matrix_generator(int **B, int k, int n){

    cout << "\nB:\n";
    for (int i = 0; i < k; i++){
        for (int j = 0; j < n; j++){
            B[i][j] = rand() % 41 - 20;
            cout << B[i][j] << " ";
        }
        cout << "\n";
    }
}


void matrix_multiply(int **A, int **B, int **C, int m, int k, int n){

    cout << "\nC\n";
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            C[i][j] = 0;
            for (int k = 0; k < n; k++){
                C[i][j] += A[i][k] * B[k][j];
            }
            cout << C[i][j] << " ";
        }
        cout << "\n";
    }
};


int main(){

    srand(time(NULL));

    int m = rand() % 10 + 1;
    int k = rand() % 10 + 1;
    int n = rand() % 10 + 1;

    cout << m << " " << k << " " << n << "\n";

    int **A = new int *[m];
    for (int i = 0; i < m; i++){
        A[i] = new int[k];
    }

    int **B = new int *[k];
    for (int i = 0; i < k; i++){
        B[i] = new int[n];
    }

    int **C = new int *[m];
    for (int i = 0; i < m; i++){
        C[i] = new int[n];
    }


    first_matrix_generator(A, m, k);
    second_matrix_generator(B, k, n);
    matrix_multiply(A, B, C, m, k, n);

    return 0;
}
