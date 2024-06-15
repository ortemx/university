#include <iostream>
#include <iomanip>
#include <windows.h>
#include <ctime>
using namespace std;
//==========================================
void mat(int *a, int n)
{
    for (int i = 0; i < n; i++)
        a[i] = rand() % 40 - 20;
}
//==========================================
void print(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        if ((i != 0) && (i * i % n == 0))
            cout << endl;
        cout << setw(4) << a[i];
    }
}
//==========================================
void sw4p(int *a, int n, int k, int m)
{
    int temp;
    for (int j = 0; j < n; j++)
    {
        temp = a[j + n * (k - 1)];
        a[j + n * (k - 1)] = a[j + n * (m - 1)];
        a[j + n * (m - 1)] = temp;
        // swap(a[j+n*(k-1)],a[j+n*(m-1)]);
    }
}
//==========================================
int main()
{
    srand(time(NULL));
    int n;
    cout << "vvedite n: ";
    cin >> n;

    int b = n * n;
    int *a = new int[b];

    mat(a, b);
    // print(a,b);

    cout << endl
         << "vvedite # strok dlya zameny:" << endl;
    int k;
    int m;
    cin >> k >> m;
    if (k > m)
        swap(k, m);
    int c = clock();
    sw4p(a, n, k, m);
    int d = clock();
    cout << d - c << endl;
    // print(a,b);
}
