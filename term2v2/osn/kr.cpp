#include <iostream>
#include <ctime>
#include <iomanip>
#include <stdlib.h>


using namespace std;

int main(){
    srand(time(NULL));
    int n;
    cin >> n;
    int *a = new int [n];

    a[0] = rand()%20-10;
    cout << setw(4) << a[0];
    int minimum = a[0];
    for (int i = 1; i < n; i++){
        a[i] = rand()%20-10;
        if (a[i] < minimum){
            minimum = a[i];
        }
        cout << setw(4) << a[i];
    }
    cout << setw(4) << "\nminimum = " << minimum << "\n";
    for (int i = 0; i < n; i++){
        if (a[i] > 0){
            a[i] = minimum;
        }
        cout << setw(4) << a[i];
    }


}
