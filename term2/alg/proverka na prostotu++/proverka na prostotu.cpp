#include <iostream>

using namespace std;

int main ()
{
    int a=0,n;
    cin>>n;
    for (int i=1; i<=n; i++)
        if (n%i==0)
            a++;
    if (a==2 ) cout<<"prostoe";
    else cout<<"ne prostoe";
    return 0;
}
