#include <iostream>
#include <iomanip>
#include <windows.h>
#include <ctime>
#include <sstream>
#include <cstdio>
#include <stdlib.h>
#include <string>

using namespace std;

//template <typename t>
void konvert(int n, string *a){
    string s;
    int ost;
    char ch;
    while (n != 0){
        ost = n % 10;
        ch = ost + 48;
        s += ch;
        n /= 10;
    }
    cout<<endl<<s<<endl;
    a[0]= s[0];
    for ( int i=0; i<s.length() ; i++ ){
        cout<<s[i];
    }
    //a[1]= s[1];
    //a[2]= s[2];
    //a[3]= s[3];
}

template <typename T>
string NumberToString ( T Number ){
    ostringstream ss;
    ss << Number;
    return ss.str();
}

int main(){
    int n = 1554;
    string s;
    konvert (n, &s);
    //konvert (n, &s);
    //cout<<"\ns="<<s;

    cout<<"\ns="<<NumberToString(42);

    int num = 122;
    string str = "";
    char buffer[3];
    sprintf(buffer, "%d", num);
    char buffer1[] = "mom";
    str = string(buffer1);
    printf("\nstr = %s", str);

return 0;
}
