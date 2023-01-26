#include <iostream>
#include <cstring>
#include <windows.h>
#include <cstdio>

using namespace std;
struct tovar
{
    string name;
    string kol;
    int ceh;
};
//=============================================
void vyborc(tovar *Cust, int n, int c)
{
    for (int i = 0; i < n; i++)
    {
        if (Cust[i].ceh == c)
        {
            cout << "tovar - " << Cust[i].name << ", v kol-ve " << Cust[i].kol << " made in ceh #"<< Cust[i].ceh;
            cout << endl;
        }
    }
}
//=============================================
void zavod(tovar *Cust, int n)
{
    for(int i = 0; i < n; i++)
    {
        fflush(stdin);
        cout << "tovar "<<i+1<<":";
        getline(cin, Cust[i].name);
        //fflush(stdin);
        cout << "kol-vo : ";
        getline(cin, Cust[i].kol);
        //cin >>  Cust[i].kol;
        cout << "# ceha: " ;
        cin >>  Cust[i].ceh;
        cout << endl;
    }
}
//=============================================
int main ()
{
    int n,c;
    cout << "vvedite chislo tovarov : ";
    cin >> n;

    tovar *Cust = new tovar[n];
    zavod(Cust,n);
    cout << endl;

    cout << "vvedite # ceha: ";
    cin >> c;
    vyborc(Cust,n,c);
    return 0;
}
