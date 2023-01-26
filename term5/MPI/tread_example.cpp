/* BASIC THREAD MANAGEMENT
 * 1. Create threads with three different callable objects (a function newValue, a lambda expression and a class operator)
 * 2. Use of join and detach methods
 * 3. Pass a ref value as argument
 */

#include <iostream>
#include <thread>
#include <vector>
#include <string>

using namespace std;

void newValue(int& value) {
    value = 2;
    string out = "[newValue] t0 new value: " + to_string(value) +" \n";
    cout << out;
}

class workClass {
public:
    void operator() (){
        string out = "[operator] t1 running\n";
        cout << out;
    };
};
int main() {
    cout << "Main thread running\n";
    vector<thread> detachPool;

    int value = 5;
    string value_out = "[main] \told value: " + to_string(value);
    thread t0(newValue, ref(value));
    //t0 must terminate before inspecting the new value
    t0.join();
    value_out += "\tnew value: " + to_string(value) + "\n";
    cout << value_out;

    thread t1{ workClass() };
    detachPool.push_back(move(t1));

    thread t2( []() {
        string out = "[lambda] t2 running\n";
        cout << out;
    });
    detachPool.push_back(move(t2));

    for(thread& t : detachPool ) {
        t.detach();
    }
    string out = "Main thread exits\n";
    cout << out;
    return 0;
}
