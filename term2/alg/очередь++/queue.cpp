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
    cout << "введите элемент: "; cin>>a;
    Queue.push(a);
}
//=====================================
template <typename T>
void del(T &Queue){
    if (Queue.empty())
        cout<<"очередь пустая"<<endl;
    else
        Queue.pop();
}
//=====================================
template<typename t>
void Empty(t &Queue){
    (Queue.empty()) ? cout<<"очередь пустая "<<endl : cout<<"очередь  не пустая"<<endl;
}
//=====================================
template <typename T>
void First(T &Queue){
    (Queue.empty()) ? cout<<"очередь пустая "<<endl : cout<<Queue.front()<<endl;
}
//=====================================
template <typename T>
void Last(T &Queue){
    (Queue.empty()) ? cout<<"очередь пустая "<<endl : cout<<Queue.back()<<endl;
}
//=====================================
int main(){
    setlocale( LC_ALL, "rus" );
    queue <int> Queue;
    int choice;
    while(choice!=6) {
        cout<<endl
        <<"выберите действие: "<<endl
        <<"1 - добавить элемент в очередь"<<endl
        <<"2 - удалить первый элемент"<<endl
        <<"3 - проверка на пустоту "<<endl
        <<"4 - вывести первый элемент"<<endl
        <<"5 - вывести последний элемент"<<endl
        <<"6 - выход"<<endl;
        cin>>choice;
        system("cls");
        switch(choice) {
            case 1 : add(Queue); break;
            case 2 : del(Queue); break;
            case 3 : Empty(Queue); break;
            case 4 : First(Queue); break;
            case 5 : Last(Queue); break;
            case 6 : break;
            default : cout<<"некорректный ввод"<<endl;
        }
    }
return 0;
}
