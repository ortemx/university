#include <iostream>
#include <cstring>
#include <windows.h>
#include <cstdio>

using namespace std;

struct order{
    string payers_account;
    string recipient_account;
    int transfer;
};

void struct_print(order *orders, int n){
    for (int i = 0; i < n; i++){
        cout << "order " << i + 1 << " information :\n ";
        cout <<  orders[i].payers_account << endl;
        cout <<  orders[i].recipient_account << endl;
        cout <<  orders[i].transfer << endl;
    }
}

void struct_sort(order *orders, int n){
    order temp;
    string min = "";
    int indexmin;
    for (int i = 0; i < n; i++){
        min = orders[i].payers_account;
        indexmin = i;
        for (int j = i; j < n; j++){
            if (orders[j].payers_account < min){
                min = orders[j].payers_account;
                indexmin = j;
            }
            temp = orders[i];
            orders[i] = orders[indexmin];
            orders[indexmin] = temp;
        }
    }
}

void transfer_info(order *orders, int n){
    string payers_name;
    cout << "enter payers name : ";
    cin >> payers_name;
    bool flag = false;
    int index;
    for (int i = 0; i < n; i++){
        if (payers_name == orders[i].payers_account){
            index = i;
            flag = true;
        }
    }
    if (flag){
        cout << "\n transfer information : " << orders[index].transfer;
    } else {
        cout << "payer not found";
    }
}

void Fill(order *orders, int n){
    for (int i = 0; i < n; i++){
        fflush(stdin);
        cout << "payers_account " << i+1 << ": ";
        getline (cin, orders[i].payers_account);
        cout << "recipient_account " << i+1 << ": ";
        cin >> orders[i].recipient_account;
        cout << "transfer amount " << i+1 << ": ";
        cin >> orders[i].transfer;
    }
}




int main(){
    int n = 8;
    order *orders = new order[n];
    Fill(orders, n);
    struct_print(orders, n);
    struct_sort(orders, n);
    struct_print(orders, n);
    transfer_info(orders, n);
    return 0;
}
