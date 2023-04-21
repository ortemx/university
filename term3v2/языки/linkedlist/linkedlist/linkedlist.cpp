#include <iostream>

using namespace std;

struct Elem
{
    char let;
    Elem *next;
};

class List
{
    Elem *head;

public:
    List() 
    { 
        head = NULL;
    }

    ~List()
    {
        while (head != NULL)
        {
            Elem *temp = head->next;
            delete head;
            head = temp;
        }
    }

    void show(Elem *beg)
    {
        Elem *tmp = beg;
        while (tmp != NULL)
        {
            cout << tmp->let;
            tmp = tmp->next;
        }
        head = beg;
    }

    void add(char let, Elem *&head)
    {
        Elem *temp = new Elem;
        temp->let = let;
        temp->next = temp;
        head->next = temp;
        head = temp;
    }
};


// Реализация класса List
int main()
{
    char let = ' ';
    List lst;
    Elem *head = new Elem;
    Elem *beg = head;
    head->next = NULL;
    cout << "enter the word: ";
    while (let != '.')
    {
        cin >> let;
        if (head->next != NULL) {
            
        }

    }

    lst.add(let, head);

    // lst.show(beg);
}
