#include <iostream>
#include <cstdlib>
//#include <stdafx>
#include <pthread.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <inttypes.h>

using namespace std;

template<class T>
class List
{
public:
    List();
    ~List();

    void push_back(T data);

private:

    template<class T>
    class node
    {
    public:
        node *pnext;
        T data;
        node(T data=T() , node *pnext = nullptr)
        {
            this->data = data;
            this->next = pnext;
        }
    };
    int s;
    node<T> *head;
};

template<class T>
List<T>::List()
{
    s=0;
    head= nullptr;
}

template<class T>
void List<T>::push_back(T data)
{
    if(head==nullptr)
    {
        head = new node <T>(data);
    }
    else
    {

    }

}


int main()
{
    List<int> lst;
    lst.push_back(5);
    return 0;
}
