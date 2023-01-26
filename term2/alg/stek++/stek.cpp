#include <iostream>
#include <iomanip>
#include <windows.h>
#include <ctime>
#include <stack>

using namespace std;

template<typename TYPE>
void add(TYPE &Stack)
{
    int a;
    cin>>a;
    Stack.push(a);
}

template<typename t>
void Topst(t &Stack)
{
    cout<<Stack.top()<<endl;
}

template<typename t>
void Empty(t &Stack)
{
    (Stack.empty()) ?
    cout<<"stek pust"<<endl
    :cout<<"stek NE pust"<<endl;
}

int main()
{
    stack <int> Stack;

    int choice;

    while(choice!=5)
    {
        cout<<"========================"<<
        endl<<"vvedite deistvie:"<<
        endl<<"1-dobavit element"<<
        endl<<"2-udalit last element"<<
        endl<<"3-proverka na pustotu"<<
        endl<<"4-vyvesti last element"<<
        endl<<"5-vyhod"<<endl;

        cin>>choice;

        switch(choice)
        {
            case 1 : add(Stack);break;
            case 2 : Stack.pop();break;
            case 3 : Empty(Stack);break;
            case 4 : Topst(Stack);break;
            case 5 : break;
            default : cout<<"nekorrektny vvod"<<endl;
        }
    }


return 0;
}
