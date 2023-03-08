#include <iostream>
#include <ctime>
#include <iomanip>
#include <stdlib.h>


using namespace std;

int main(){
    srand(time(NULL));
    int n;
    cin >> n;
    int **a = new int*[n];

    for (int i = 0; i < n; i++){
        a[i] = new int [n];
    }
    for(int i=0;i<n;i++){
        cout<<endl;
        for(int j=0;j<n;j++){
        a[i][j]=rand()%41-20;
            cout<<setw(3)<<a[i][j]<<" ";
        }
    }
    int temp;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n/2; j++){
            temp = a[i][j];
            a[i][j] = a[i][n-j-1];
            a[i][n-j-1] = temp;
        }
    }
    for(int i=0;i<n;i++){
        cout<<endl;
        for(int j=0;j<n;j++){
            cout<<setw(3)<<a[i][j];
        }
    }
}
