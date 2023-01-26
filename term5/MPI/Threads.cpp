#include <iostream>
#include <thread>
#include <ctime>
#include <windows.h>
using namespace std;


void print (int i, int& result){
    Sleep(1000);
    result += 1000;
    cout << i << " ";
}


int main(){

    int result = 0;

    int threads_count = thread::hardware_concurrency();
    thread* threads = new thread[threads_count];


    for (int i = 0; i < threads_count; i++){
        //threads[i] = thread(print, i, ref(result));
        //threads[i].join();
    }

    for (int i = 0; i < threads_count; i++){
        threads[i] = thread(print, i, ref(result));
        threads[i].detach();
    }

    for (int i = 0; i < threads_count; i++){
        //threads[i].join();
    }

    cout << "\nresult = " << result;
    cout << "\ncount of cores = " << thread::hardware_concurrency();
    SYSTEM_INFO sysinfo;
    GetSystemInfo(&sysinfo);
    cout << "\ncount of cores = " << sysinfo.dwNumberOfProcessors;
    int num = 1;
    return 0;
}
