#include <iostream>
//#include <stdio.h>
#include <iomanip>

//using namespace std;
int main()
{
    int mes[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int dn[7]={1,2,3,4,5,6,7};
    std::string den;
    int t,k,n;
//======================================
    for (int j=0;j<7;j++)
    {
        k=0;
        n=dn[j];
        switch (n)
        {
        case 1:den="pn"; break;
        case 2:den="vt"; break;
        case 3:den="sr"; break;
        case 4:den="ch"; break;
        case 5:den="pt"; break;
        case 6:den="sb"; break;
        case 7:den="vs"; break;
        }
        std::cout<<"esli den nedeli"<<std::setw(3)<<den<<std::endl;

        if (n==3) k+=1;
        for (int i=1;i<12;i++)
        {
            t=n+mes[i-1];
            if (t%7==3) k+=1;
            n=t%7;
        }
        std::cout<<"to kol-vo poned na 13 chislo ="<<std::setw(3)<<k<<std::endl;
    }
    delete[] mes;
    delete[] dn;
    return 0;
}
