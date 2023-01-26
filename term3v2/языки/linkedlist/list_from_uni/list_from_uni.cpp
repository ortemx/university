// signlist.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>
#include <list>
using namespace std;


struct elem {
	char letter;
	elem* next;
};

class list_ {
	elem* begin;
	elem* prev;
	elem* end;
public:
	list_() {
		this->begin = NULL;
		this->prev = NULL;
		this->end = NULL;
	}
	list_(elem* head) { 
		this->begin = head;
		this->begin->next = NULL;
		this->prev = NULL;
		this->end = head;
		this->end->next = NULL;
	}
	~list_() {};
	template <typename T>
	void push_back(T data) {
		if (this->begin == NULL) {
			elem* temp = new elem;
			temp->letter = data;
			temp->next = NULL;
			this->begin = temp;
			this->end = temp;
		}
		else {
			elem* temp = new elem;
			temp->letter = data;
			temp->next = NULL;
			this->end->next = temp;
			this->end = temp;
		}
	}
	void show() {
		elem* p = this->begin;
		while (p != NULL) {
			cout << p->letter;
			p = p->next;
		}
	}
	//template <typename T>
	void erase() {
		elem* p = this->begin;
		while (p != NULL) {
			if (p->letter < 48 || p->letter > 57) {
				// если удаляется первое звено
				if (p == this->begin) {
					p = p->next;
					delete begin;
					this->begin = p;
					this->prev = p;
				}
				// если удаляется не первое звено
				else {
					this->prev->next = p->next;
					delete p;
					p = this->prev->next;
				}
			}
			else {
				this->prev = p;
				p = p->next;
			}
		}
	}
};

int main()
{
	list_ lst;
	char x = 0;
	cout << "enter the word by character: \n";
	while (x != '.') {
		cin >> x;
		lst.push_back(x);
	}
	cout << "\nbefore: ";
	lst.show();
	lst.erase();
	cout << "\nafter: ";
	lst.show();
	cout << "\n";
	system("pause");
	return 0;
}