#include <iostream>
#include <iomanip>
#include <windows.h>
#include <ctime>

using namespace std;

struct element
{
    char x;
    element *next;
};

void push_back(element* &head) //добавление
{
    char letter;

    do {
        cout<<endl<<"vvedite bukvu"<<endl;
        cin>>letter;

        if (head == NULL) {
            head = new element();
            head->x = letter;
        }
        else {
            element *i = head;
            while (i->next != NULL)
                i = i->next;
            i->next = new element();
            i->next->x = letter;
        }
    } while (letter != '.');
}

void print(element* head)
{
    if (head!=NULL)
    {
        cout<<setw(3)<<head->x;
        print(head->next);
    }
    cout<<endl;
}

void change (element* head)
{
    char pivot, elem;
    cout<<endl<<"vvedite simvol"<<endl;
    cin>>pivot;

    element* ptr = head;
    while (ptr != NULL)
    {
        if  (ptr->x == pivot)
            cout<<"..";
        ptr = ptr ->next;
    }
}

void change2 (element* head)
{
    char pivot, elem;
    cout<<endl<<"vvedite simvol"<<endl;
    cin>>pivot;

    element* ptr = head;
    while (ptr != NULL)
    {
        if  (ptr->x == pivot){
            element* ptr2 = ptr->next;
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
    element *head=NULL;

    push_back(head);
    print(head);
    //change (head);
    change2 (head);
    print(head);



return 0;
}
