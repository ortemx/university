#include <iostream>
#include <cmath>
#include <windows.h>
#include <iomanip>
using namespace std;
//=================================
void sum(int** a,int n,int m)
{
    for(int i=0;i<n;i++)
    {
    int k=0;
    for(int j=0;j<m;j++)
    if(a[i][j]>0)
    k=k+a[i][j];
    cout<<k<<endl;
    }
}
//=================================
void create(int** a,int n,int m)
{
    for(int i=0;i<n;i++)
    {
        cout<<endl;
        for(int j=0;j<m;j++)
        {
            a[i][j]=rand()%41-20;
            cout<<setw(3)<<a[i][j];
        }
    }
}
//=================================
int main()
{
int n,m,k,t;
cin>>n>>m>>k>>t;
cout<<endl;
   int **a = new int*[n];
   for(int i=0;i<n;i++)
    a[i]=new int[t];

   int **b = new int*[k];
   for(int i=0;i<k;i++)
    b[i]=new int[t];

cout<<"mat a";
create(a,n,m);
cout<<endl<<endl;

cout<<"mat b";
create(b,k,t);
cout<<endl<<endl;

sum (a,n,m);

cout<<endl;
sum (b,k,t);

return 0;

}
