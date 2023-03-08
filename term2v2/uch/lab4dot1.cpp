#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    int n;
    cout << "enter n " << endl;
    cin >> n;
    int **A = new int * [n];
    for (int i = 0; i < n; i++){
        A[i] = new int [n];
    }
    for (int i = 0; i < n; i++){
        cout <<"\n";
        for (int j = 0; j < n; j++){
            if (i == j)
                A[i][j] = (i+1)*(j+2);
            else
                A[i][j] = 0;
            cout << setw(5) << A[i][j] ;
        }

    }


    return 0;
}
