#include <iostream>
#include <iomanip>
#include <windows.h>
#include <ctime>

using namespace std;
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <ctime>

using namespace std;

struct list
{
    char x;
    list *next;
};

void add(list* &head)
{
    list* newEL = new list;
    newEL->next=NULL;
    head=newEL;
    list* count=head;
    cout<<"¬ведите слово:";
    char el;

    while(el != '.')
    {
        cin>>el;
        newEL->x=el;
        list* newEL = new list;
        count->next=newEL;
        count=newEL;
    }
}

void print(list* head)
{
    if (head!=NULL)
    {
        cout<<setw(3)<<head->x;
        print(head->next);
    }
    cout<<endl;
}

void change (list* head)
{
    char pivot, elem;
    cout<<endl<<"vvedite simvol"<<endl;
    cin>>pivot;

    list* ptr = head;
    while (ptr != NULL)
    {
        if  (ptr->x == pivot)
            cout<<"..";
        ptr = ptr ->next;
    }
}

void change2 (list* head)
{
    char pivot, elem;
    cout<<endl<<"vvedite simvol"<<endl;
    cin>>pivot;

    list* ptr = head;
    while (ptr != NULL)
    {
        if  (ptr->x == pivot){
            list* ptr2 = ptr->next;
            if ((ptr2->x != pivot)  &&
                (ptr2->x != '.')    &&
                (ptr2->next != NULL)){
                    ptr->next = ptr2->next;
                }
        }
        ptr = ptr ->next;
    }
}

int main()
{
    list *head=NULL;
    add(head);
    //push_back(head);
    print(head);
    //change (head);
    change2 (head);
    print(head);
    change2 (head);
    print(head);



return 0;
}
