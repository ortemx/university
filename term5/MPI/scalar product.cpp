#include <iostream>
#include <ctime>
#include <iomanip>
#include <stdlib.h>
#include <fstream>

using namespace std;

void SP(int *v1, int *v2, int *v3, int n){
    for (int i = 0; i < n; i++){
        v3[i] = v1[i] * v2[i];
        cout << v3[i] << " ";
    }
};

int main(){

    srand(time(NULL));

    int n = 10;
    int *v1 = new int [n];
    int *v2 = new int [n];
    int *v3 = new int [n];

    for(int i = 0; i < n; i++){
        v1[i] = rand() % 41 - 20;
        v2[i] = rand() % 41 - 20;
    }

    SP(v1, v2, v3, n);

    return 0;
}
