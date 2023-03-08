#include <iostream>
#include <iomanip>
#include <vector>
#include <windows.h>
#include <string>
#include <cstdio>
#include <ctime>

using namespace std;
int main(){
    const int n = 14;
    srand(time(NULL));
    vector <int> a(n);
    vector<int>::iterator a_iter;
    for (int i = 0; i < n; i++){
        a[i] = (rand()%30-15);
        cout <<a[i] << " ";
    }
    // part 1
    int amount;
    cout << "\nenter amount: ";
    cin >> amount;
    int pos;
    cout << "enter position: ";
    cin >> pos;
    a_iter = a.begin();
    a.erase(a_iter + pos, a_iter + pos + amount);
    for (int i = 0; i < a.size(); i++){
        cout <<a[i] << " ";
    }
    // part 2
    int element;
    cout << "\nenter element: ";
    cin >> element;
    cout << "enter position: ";
    cin >> pos;
    a.insert(a_iter + pos, element);
    for (int i = 0; i < a.size(); i++){
        cout <<a[i] << " ";
    }
    // part 3
    int temp;
    for (int i = 0; i < a.size() - 1; i += 2){
        temp = a[i];
        a[i] = a[i+1];
        a[i+1] = temp;
    }
    cout << endl;
    double average = 0;
    for (int i = 0; i < a.size(); i++){
        average += a[i];
        cout <<a[i] << " ";
    }
    // part 4
    average /= a.size();
    cout << "\naverage = " << average << "\n";
    bool flag = false;
    for  (int i = 0; i < a.size(); i++){
        if (a[i] == average){
            cout << "index: " << i;
            flag = true;
            break;
        }
    }
    if (!flag){
        cout <<"\nelement no found\n";
    }

    // part 5
    for (int i = 0; i < a.size(); i++){
        for (int j = 0; j < i; j++){
            if (a[i] < a[j]){
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    for (int i = 0; i < a.size(); i++){
        cout <<a[i] << " ";
    }


    return 0;
}
