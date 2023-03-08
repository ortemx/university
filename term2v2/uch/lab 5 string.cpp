#include <iostream>
#include <string.h>

using namespace std;

int main(){
    string str = "nugy5c4q";
    char f;
    int c(0);
    for (int i(0); i < str.length() - 1; i++){
        f = str[i];
        for (int j = i+1; j < str.length(); j++){
            if (f == str[j]){
                c++;
            }
        }
        if (c){
            break;
        }
    }
    cout << (c ? "not all letters are different" : "all letters are different");

    return 0;
}
