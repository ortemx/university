#include <iostream>
#include <windows.h>
#include <ctime>
#include <iomanip>
using namespace std;

int main(){
    srand(time(NULL));
    int n(15);
    int index_min_1, index_min_2;
    //cin >> n;
    int * a = new int[n];
    for(int i = 0; i < n; i++){
        a[i] = rand()%20-10;
        cout << setw(4) << a[i] ;
    }
    index_min_1 = 0;
    index_min_2 = 1;
    if (a[0] > a[1]){
        index_min_1 = 1;
        index_min_2 = 0;
    }
    int temp;
    for (int i = 2; i < n; i++){
        if (a[i] < a[index_min_2]){
            if (a[i] < a[index_min_1]){
                temp = index_min_1;
                index_min_1 = i;
                index_min_2 = temp;
            } else {
                index_min_2 = i;
            }
        }
    }
    if (index_min_1 > index_min_2){
        temp = index_min_1;
        index_min_1 = index_min_2;
        index_min_2 = temp;
    }

    if (index_min_1 != index_min_2 - 1){
        int p = 1;
        for (int i = index_min_1 + 1; i < index_min_2; i++){
            p *= a[i];
        }
        cout << "\nP = " << p << "\n";
    } else {
        cout << "\nP = 0";
    }

    //  " sort "
    int first = 0;
    int last = n - 1;
    while (first < last-1){
        if (a[first] >= 0){
            //cout << "\nf = " <<first << "; l = " << last;
            //cout << "\na[last] < 0? " << (a[last] < 0);
            while (a[last] >= 0){
                last--;
            }
            //cout << "last = " << last << "\n";
            //cout << "f = " <<first << "; l = " << last;
            temp = a[first];
            a[first] = a[last];
            a[last] = temp;
        }
        first++;
        //cout << endl;
        for(int i = 0; i < n; i++){
            //cout << setw(4) << a[i] ;
        }
    }
    cout << endl;
    for(int i = 0; i < n; i++){
        cout << setw(4) << a[i] ;
    }
    return 0;
}
