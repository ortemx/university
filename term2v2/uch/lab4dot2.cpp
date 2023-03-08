#include <iostream>
#include <iomanip>
#include <ctime>
#include <windows.h>
#include <vector>
using namespace std;
int main(){
    //srand(time(NULL));
    int n, m;
    cout << "enter n and m" << endl;
    cin >> n >> m;
    int **A = new int * [n];
    for (int i = 0; i < n; i++){
        A[i] = new int [m];
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            A[i][j] = rand()%100 - 50;
            cout << setw(4) << A[i][j];
        }
        cout <<"\n";
    }
    int countOfpositive(0);
    vector <int> index;
    for (int j = 0; j < m; j++){
        countOfpositive = 0;
        for (int i = 0; i < n; i++){
            if (A[i][j] > 0)
                countOfpositive++;
        }
        if (countOfpositive != n)
            index.push_back(j);
    }
    int **B = new int *[n];
    for (int i = 0; i < n; i++){
        B[i] = new int[index.size()];
    }
    for (int i = 0; i < index.size(); i++){
        //cout << index[i] << " ";
    }
    cout <<"\n";

    for (int j = 0; j < index.size(); j++){
        for (int i = 0; i < n; i++){
            B[i][j] = A[i][index[j]];
        }
    }



    for (int i = 0; i < n; i++){
        for (int j = 0; j < index.size(); j++){
            cout << setw(4) << B[i][j];
        }
        cout <<"\n";
    }



    return 0;
}
