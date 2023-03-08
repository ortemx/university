#include <iostream>
#include <ctime>
#include <iomanip>
#include <stdlib.h>
#include <cmath>


using namespace std;
// b = true if E "-"
//     else
int main(){
    srand(time(NULL));
    int n, m;
    cin >> m >> n;

    int **a = new int*[m];
    for (int i = 0; i < m; i++){
        a[i] = new int [n];
    }
    bool * b = new bool [n];
    for(int i=0;i<m;i++){
        cout<<endl;
        for(int j=0;j<n;j++){
        a[i][j]=rand()%41-5;
            cout<<setw(3)<<a[i][j]<<" ";
        }
    }
    bool temp;
    for(int j = 0; j < n; j++){
        int i = 0;
        b[j] = !(a[i][j] >> 31);
        //cout << "\nb1 ="<< b[j] << endl;
        for(i = 1; i < m; i++){
            b[j] =  b[j] && !(a[i][j] >> 31);
            //cout << "b1 =" << b[j] << endl;
        }
        b[j] = !b[j];
        //cin >> temp;
    }
    cout << endl;
    for(int j = 0; j < n; j++){
        cout << setw(4) << b[j];
    }

    int z = 15;
    z = (z >> 31);
    //cout << "\nz = " << (bool)-z;
}
