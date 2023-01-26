#include <iostream>

int main()
{
    int n,m=1;
    std::cin>>n;

    for (int i=1; i<=n;i++)
    m=m*i;

    std::cout<<m<<std::endl;
    return 0;
}
