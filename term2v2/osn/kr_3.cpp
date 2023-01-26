#include <iostream>
#include <ctime>
#include <iomanip>
#include <stdlib.h>


using namespace std;

int main(){
    srand(time(NULL));
    int n, m;
    cin >> n >> m;
    int **a = new int*[n];
    for (int i = 0; i < m; i++){
        a[i] = new int [m];
    }
    for(int i=0;i<n;i++){
        cout<<endl;
        for(int j=0;j<m;j++){
        a[i][j]=rand()%41-20;
            cout<<setw(3)<<a[i][j]<<" ";
        }
    }
    int k1, k2;
    cout << endl;
    cin >> k1 >> k2;
    int temp;
    for (int i = 0; i < n; i++){
        temp = a[i][k1-1];
        a[i][k1-1] = a[i][k2-1];
        a[i][k2-1] = temp;
    }
    for(int i=0;i<n;i++){
        cout<<endl;
        for(int j=0;j<m;j++){
            cout<<setw(3)<<a[i][j]<<" ";
        }
    }

}
