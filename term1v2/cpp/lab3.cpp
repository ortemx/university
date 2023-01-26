#include <iostream>
#include <iomanip>
#include <windows.h>
#include <ctime>

using namespace std;


int main(){

    srand(time(NULL));
    int q;
    int n = 20;
    int odd = 0;
    q = -50 + rand()% 30 ;
    cout<<"1 "<<q<<" "<<odd<<endl;
    int min_q = q;
    if (q % 2 != 0)
        odd++;
    for (int i = 0; i < n-1; i++){
        q = -50 + rand()% 30;
        cout<<i+2<<" "<<q<<" "<<odd<<endl;
        if (q < min_q)
            min_q = q;
        if (q % 2 != 0)
            odd++;
    }

    cout<<endl<<min_q<< " "<<odd;



return 0;
}
