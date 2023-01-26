#include <iostream>

using namespace std;

int NOD(int A, int B)
{
    while (A!=B)
    if (A>B) A-=B;
    else B-=A;
    return A;
}

int NOD2(int A, int B)
{
    while (A!=0 && B!=0)
    if (A>B)
        A%=B;
    else
        B%=A;
    return A+B;
}

int main ()
{
    setlocale(LC_ALL,"Rus");
    int A, B;
    cin>>A;
    cin>>B;
    cout<<"мнд("<<A<<", "<<B<<")="<<NOD(A, B);
    cout<<endl<<"мнд("<<A<<", "<<B<<")="<<NOD2(A, B);
}
