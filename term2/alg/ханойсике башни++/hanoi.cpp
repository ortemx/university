#include <iostream>
#include <iomanip>
#include <windows.h>
#include <ctime>

using namespace std;

void hanoi(int kolich, int start, int last, int prom)
{
    if (kolich!=0)
    {
        kolich--;
        hanoi(kolich, start, prom, last);
        cout << "s " <<start << " na " << last << endl;
        hanoi(kolich, prom, last, start);
    }
}

int main()
{
    int start=1;
    int prom=2;
    int last=3;

    int kolich;
    cout << "kol-vo diskov:" << endl;
    cin  >> kolich;

    hanoi(kolich, start, last, prom);
return 0;
}
