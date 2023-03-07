#include <iostream>
#include <iomanip>
// #include <windows.h>
#include <ctime>

using namespace std;


int main(){

    srand(time(NULL));
    int q;
    int n = 20;
    int odd = 0;
    q = - 50 + rand() % 30 ;
    printf("1 %d %d\n", q, odd);
    int min_q = q;
    if (q % 2 != 0) {
        odd++;
    }

    for (int i = 0; i < n - 1; i++) {
        q = -50 + rand() % 30;
        printf("%d %d %d\n", i+2, q, odd);
        if (q < min_q) {
            min_q = q;
        }

        if (q % 2 != 0) {
            odd++;
        }
    }
    printf("%d %d\n", min_q, odd);

    return 0;
}
