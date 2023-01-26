#include <iostream>

using namespace std;

int main()
{
    unsigned long long int n, sum, n1=1, n2=1;
    cin >> n;

    if(n == 0)
        return 0;
    if(n == 1 || n == 2)
        return 1;
    for (int i = 2; i < n; i++) {
        sum = n1 + n2;
        n1 = n2;
        n2 = sum;
    }
    cout << sum << endl;
    return 0;
}
