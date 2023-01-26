#include <iostream>

using namespace std;

unsigned long long int Peano(int n){
    if(n == 0)
        return 0;
    else if(n == 1 || n == 2)
        return 1;
    return Peano(n-1)+Peano(n-2);
}

int main()
{
    int n;
    cout<<"vvedite nomer chisla posledovatelnosti"<<endl;
    cin>>n;

    cout<< Peano(n);
    return 0;
}
