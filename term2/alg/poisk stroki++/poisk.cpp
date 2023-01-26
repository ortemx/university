#include <iostream>
#include <iomanip>
#include <windows.h>
#include <ctime>
#include <cstring>

using namespace std;

void ssearch(string s1, string s2)
{
    int res = -1;
    int sl = s1.length();
    int ssl = s2.length();
    for (int i = 0; i < sl - ssl + 1; i++){
        for (int j = 0; j < ssl; j++){
            if (s2[j] != s1[i+j])
                break;
            else if ( j == ssl - 1 ){
                res = i;
                break;
            }
        }
        cout << res << "\n";
    }
}

int main()
{
    string s1="caccac";
    string s2="ac";
    ssearch(s1,s2);

return 0;
}
