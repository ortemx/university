#include <iostream>
#include <windows.h>
using namespace std;
struct list{
list *next;
char data;
};

void flip(list* &start, int count)
{
    if(count==0) return;
    int i;
    list* current=start;
    for(i=0;i<count;i++)
        current=current->next;
    cout<<current->data;
    flip(start,count-1);
}

void alg(list* &head)
{
    list* start;
    list* current=head;
    int count=0;
    while(current != NULL){
    start=current;
    while(current->data != '.' || ' ')
    {
        cout<<current->data;
        current=current->next;
        count++;
    }
    if(current->data=='.')
    {
        flip(start,count);
        current=current->next;
        current=current->next;
    }
    else current=current->next;
}
}
void add(list* &head)
{
    list* newEL = new list;
    newEL->next=NULL;
    head=newEL;
    list* count=head;
    cout<<"¬ведите слов";

    while(newEL->data != '.')
    {
        cin>>newEL->data;
        list* newEL = new list;
        count->next=newEL;
        count=newEL;
    }

}

int main()
{
SetConsoleOutputCP(1251);
list *head=NULL;
add(head);
alg(head);

return 0;
}
