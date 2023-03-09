#include <iostream>
#include <windows.h>
#include <iomanip>
#include <ctime>

using namespace std;

int NOD(int n1, int n2)
{
  int div;
  if (n1 == n2)  return n1;
  int d = n1 - n2;
  if (d < 0) {
    d = -d;  div = NOD(n1, d);
  } else
    div = NOD(n2, d);
  return div;
}

int NOK(int n1, int n2)
{
  return n1*n2 / NOD(n1, n2);
}

int main (){

    int a, b, c, d, num, denum, integer_part, temp;
    //cout << enter
    a = 3;
    b = 8;
    c = 3;
    d = 4;

    a *= NOK(b, d) / b;
    c *= NOK(b, d) / d;
    b = NOK(b, d);
    d = NOK(b, d);

    num = a + c;
    denum = b;
    if (NOD(num, denum) != 1){
        temp = NOD(num, denum);
        num /= temp;
        denum /= temp;
    }

    if (num >= denum){
        integer_part = num / denum;
        num -=  integer_part * denum;
        if (num == 0){
            cout << integer_part;
        }else {
            cout << integer_part << " " << num << "/" << denum;
        }
    } else {
        cout << num << "/" << denum;
    }






    return 0;
}
