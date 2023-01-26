#include <iostream>
#include <ctime>
#include <iomanip>
#include <windows.h>

using namespace std;
int main(){
    srand(time(NULL));
    int n = 5;
    int k(0);
    cout << "enter n: ";
    cin >> n;
    int *A = new int [n];
    for (int i = 0; i < n; i++){
        A[i] = rand()%6 - 3;
        cout << A[i] << " ";
    }

    for (int i = 0; i < n-1; i++){
        if (A[i] * A[i+1] < 0)
            k++;
    }
    cout << "\nk = " << k;
    return 0;
}
