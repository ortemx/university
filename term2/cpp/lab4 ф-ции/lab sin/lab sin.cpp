#include <iostream>
#include <cmath>
#include <windows.h>
#include <iomanip>
using namespace std;
//=================================
float sum(int* a,int n){
    float k=0;
    for(int i=0;i<n;i++) {
        cout<<sin(a[i])<<endl;
        k=k+sin(a[i]);
        cout<<"summa sinusov elementov = "<<k<<endl;
        return k;
    }
}
//=================================
void create(int* a,int n){
    for(int i=0;i<n;i++){
        a[i]=rand()%41-20;
        cout<<setw(3)<<a[i]<<" ";
    }
}
//=================================
int main()
{
    int n,m; float z;
    cout<<"vvedite razmerost 2 matric"<<endl;
    cin>>n>>m;
    cout<<endl;
    int *x = new int[n];
    int *y = new int[m];

    cout<<"mat x"<<endl;
    create(x,n);
    cout<<endl<<endl;

    cout<<"mat y"<<endl;
    create(y,m);
    cout<<endl<<endl;

    float x1=sum (x,n);
    cout<<endl;
    float y1=sum (y,m);

    z=(x1-y1)/2;
    cout<<"z= "<<z;
    return 0;
}
