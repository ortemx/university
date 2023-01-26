#include <iostream>
#include <iomanip>
#include <windows.h>
#include <ctime>

using namespace std;

struct element
{
    int x;
    element *Next;
    element *pred;
};

void Make(int n, element** Head, element* pred){

  if (n > 0) {
    (*Head) = new element();
     //выделяем память под новый элемент
    cout << "Введите значение ";
    cin >> (*Head)->x;
    //вводим значение информационного поля
    (*Head)->pred = pred;
    (*Head)->Next=NULL;//обнуление адресного поля
    Make(n-1,&((*Head)->Next),(*Head));
  }
  else (*Head) = NULL;
}

void Print(element* Head) {
  if (Head != NULL) {
    cout << setw(4)<<Head->x;
    Print(Head->Next);
  }
}

void alg(int n, element* Head){
    int sum=0;
    int p1,p2;
    element *z = Head;
    for ( int i=0; i<n-1 ; i++ ){
        z = z->Next;
    }
    element *a = Head;
    for ( int i=0; i<n ; i++ ){
        p1 = a->x;      cout<<" p1="<<p1;
        p2 = z->x;      cout<<" p2="<<p2;
        sum+=p1*p2;     cout<<" sum="<<sum<<endl;
        a = a->Next; z = z->pred;
    }
    cout<<sum;
}
int main()
{
    setlocale( LC_ALL,"Russian" );

    element *head = NULL;
    element *prior = NULL;
    int n = 3;
    Make (n, &head, prior);
    //Print(head);
    alg(n, head);

return 0;
}
