#include <iostream>
#include <ctime>
#include <iomanip>
#include <stdlib.h>


using namespace std;

int main(){
    srand(time(NULL));
    int n;
    cin >> n;
    int a;
    int index = 0;
    int minimum;
    cin >> a;
    if (a % 2 == 0){
        index = 1;
        minimum = a;
    }
    for (int i = 2; i <= n; i++) {
        cin >> a;
        if (a % 2 == 0){
            if (index == 0){
                minimum = a;
                index = i;
            }
            else {
                if (a < minimum){
                    minimum = a;
                    index = i;
                }
            }
        }
    }

    if (index){
        cout << "index is "<<index;

    } else {
        cout << "index no found";
    }
}
