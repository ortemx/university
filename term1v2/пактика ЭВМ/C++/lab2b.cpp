#include <iostream>
#include <windows.h>
#include <iomanip>
#include <ctime>

using namespace std;

int main (){

    int n;
    cout << "enter n " ; cin >> n;
    int q;
    int k = 0;
    int i = 1;
    int q_min;
    while (i <= n) {
        cout << "enter q" << i << " "; cin >> q;
        if (i == 1){
            q_min = min(q, q-1);
        }
        if (q % 2 == 0) {
            if (q < q_min){
               q_min = q;
            }
            k++;
        }
        i++;
    }
    cout << "q min = "<< q_min << " number of odd = " << n - k;

    return 0;
}
