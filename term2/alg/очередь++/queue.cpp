#include <iostream>
#include <iomanip>
#include <windows.h>
#include <ctime>
#include <queue>

using namespace std;
//=====================================
template <typename T>
void add(T &Queue){
    int a;
    cout << "������� �������: "; cin>>a;
    Queue.push(a);
}
//=====================================
template <typename T>
void del(T &Queue){
    if (Queue.empty())
        cout<<"������� ������"<<endl;
    else
        Queue.pop();
}
//=====================================
template<typename t>
void Empty(t &Queue){
    (Queue.empty()) ? cout<<"������� ������ "<<endl : cout<<"�������  �� ������"<<endl;
}
//=====================================
template <typename T>
void First(T &Queue){
    (Queue.empty()) ? cout<<"������� ������ "<<endl : cout<<Queue.front()<<endl;
}
//=====================================
template <typename T>
void Last(T &Queue){
    (Queue.empty()) ? cout<<"������� ������ "<<endl : cout<<Queue.back()<<endl;
}
//=====================================
int main(){
    setlocale( LC_ALL, "rus" );
    queue <int> Queue;
    int choice;
    while(choice!=6) {
        cout<<endl
        <<"�������� ��������: "<<endl
        <<"1 - �������� ������� � �������"<<endl
        <<"2 - ������� ������ �������"<<endl
        <<"3 - �������� �� ������� "<<endl
        <<"4 - ������� ������ �������"<<endl
        <<"5 - ������� ��������� �������"<<endl
        <<"6 - �����"<<endl;
        cin>>choice;
        system("cls");
        switch(choice) {
            case 1 : add(Queue); break;
            case 2 : del(Queue); break;
            case 3 : Empty(Queue); break;
            case 4 : First(Queue); break;
            case 5 : Last(Queue); break;
            case 6 : break;
            default : cout<<"������������ ����"<<endl;
        }
    }
return 0;
}
