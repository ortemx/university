#include <iostream>
using namespace std;

void algorithm( string str){
    bool find = 0;
    string sz = ".,/!";
    string str1 = "";
    str = str + ' ';

    for( int i = 0; i < str.size(); i++ )
        if ( sz.find( str[i] ) != -1 )
            str[i] = ' ';
    cout<<str<<endl;;
    for( int i = 0; i < str.size(); i++ ){
        if (str[i] != ' ')
            str1 += str[i];
        else {
            int k = str1.size();
            if ( k > 1 && str1[0] == 'm' && str1[k-1] == 'a' ){
                find = 1;
                cout<<str1<<endl;
            }
            str1 = "";
        }
    }
    if ( !find  )
        cout<<"slov net";
}
int main(){
    string str="mama,, m,a1 a /ma1a/ mama, ma11a! mama, ma1a1ma.";
    //str = "trt thytr htrhtr hx n jtjy";
    algorithm(str);
}
