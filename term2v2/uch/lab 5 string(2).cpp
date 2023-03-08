#include <iostream>
#include <string>

using namespace std;

int main(){
    string str = "nugy5c, ,fcgdf ery 5y ,fh0, ,,, !9q";
    string str_2 = "";
    cout
    cin >> str;
    int i = 0, temp;
    while (i < str.length()){
        temp = i;
        if (int(str[i]) > 96 && int(str[i]) < 123 || 47 < int(str[i])  && int(str[i]) < 58){
            while (int(str[i]) > 96 && int(str[i]) < 123|| 47 < int(str[i])  && int(str[i]) < 58){
                i++;
            }
            str_2 = str.substr(temp, i - temp) + " " + str_2;
        }
        i++;
    }
    cout << str_2;
    return 0;
}
