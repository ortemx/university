#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

int main(){
    string str = "...d.d.  d...d.d.dd.d d......dd.ddd   ..d.d..";
    for(int i = 1; i < str.length();){
        if ((str[i] == '.') && (str[i-1] == '.')){
            str.erase(i, 1);
        }else{
            i++;
        }
    }
    cout << str;

    //
    string empty_str = "";
    cout << "\n " << str.substr(5,6);
    system("pause");
    return 0;
}
