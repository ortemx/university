#include <iostream>
#include <iomanip>
#include <windows.h>
#include <ctime>

using namespace std;

struct element
{
    int x;
    element *next;
};

void push_back(element* &head) //добавление
{
    int elem;
    cout<<endl<<"vvedite new element:"<<endl;
    cin>>elem;

    if (head == NULL) {
        head = new element();
        head->x = elem;
    }
    else {
        element *i = head;
        while (i->next != NULL)
            i = i->next;
        i->next = new element();
        i->next->x = elem;
    }
    cout<<endl;
}

void Search(element* head) //поиск элемента
{
    int DataItem;
    cout<<endl<<"vvedite element dlya poiska"<<endl;
    cin>>DataItem;
    int kol=1;

    element* ptr;
    ptr = head;
    while (ptr!=NULL)
    {
        if (DataItem == ptr->x)
            cout<<"element pщd nomerom "<<kol<<endl;
        ptr = ptr->next;
        kol++;
    }
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

void Delete(element* head)
{
    int DataItem;
    cout<<endl<<"vvedite element dlya udaleniya"<<endl;
    cin>>DataItem;

    element* ptr;
    element* ptr1;
    ptr = head;
    while (ptr!=NULL)
    {
        ptr1 = ptr->next;
        //cout<<ptr1->x;
        if (ptr1->x == DataItem)
        {
            ptr=ptr1->next;
            ptr1->next=NULL;
            delete(ptr1);
        }
        ptr = ptr->next;
    }
}

void Clean(element* head)
{
    if (head!=NULL)
    {
        Clean(head->next);
        delete head;
    }
}

int main()
{
    element *head=NULL;
    int choice;

    while(choice!=5)
    {
        cout<<"========================"<<
        endl<<"vvedite deistvie:"<<
        endl<<"1-dobavit element"<<
        endl<<"2-poisk"<<
        endl<<"3-vyvod"<<
        endl<<"4-udalit element"<<
        endl<<"5-vyhod"<<endl;

        cin>>choice;

        switch(choice)
        {
            case 1 : push_back(head);break;
            case 2 : Search(head);break;
            case 3 : print(head);break;
            case 4 : Delete(head);break;
            case 5 : Clean(head);break;
            default : cout<<"nekorrektny vvod"<<endl;
        }
    }
return 0;
}
