#include <windows.h>
#include <iostream>

using namespace std;

int main(){
    long long start = 0;
    double PCFreq = 0.0;

    long long finish = 0;
    LARGE_INTEGER li;

    QueryPerformanceFrequency(&li);
    PCFreq = double(li.QuadPart) / 1000.0;
    QueryPerformanceCounter(&li);
    start = li.QuadPart;

    Sleep(1000);

    QueryPerformanceCounter(&li);
    finish = li.QuadPart;

    cout << "\nTime: " << (finish - start) / PCFreq << "\n";

    return 0;
}
