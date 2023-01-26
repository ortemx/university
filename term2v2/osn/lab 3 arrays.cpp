#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    int A[3][3] = {{7, 2, 0}, {-7, -2 ,1}, {1, 1, 1}};
    int B[3][3] = {{0, 2, 3}, {1, 0, -2}, {3, 1, 1}};
    cout << "A:" << endl;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cout << setw(5) << A[i][j];
        }
        cout << "\n";
    }
    cout << "B:" << endl;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cout << setw(5) << B[i][j];
        }
        cout << "\n";
    }
    int C[3][3];
    int D[3][3];
    int F[3][3];
    int p, t;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            //D[i][j] = A[i][j] + B[i][j];
            p = 0;
            t = 0;
            for (int k = 0; k < 3; k++){
                p += A[i][k] * A[k][j];
                t += B[i][k] * B[k][j];
            }
            F[i][j] = p - t;
        }
    }
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            C[i][j] = 0;
            for (int k = 0; k < 3; k++){
                //C[i][j] += F[i][k] * D[k][j];
                C[i][j] += F[i][k] * (A[k][j] + B[k][j]);
            }
        }
    }
    cout << "C = ((sqr(A) - sqr(B)) * (A + B)" << endl;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cout << setw(5) << C[i][j];
        }
        cout << "\n";
    }

    return 0;
}
