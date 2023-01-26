// linkedlist_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

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
	void replace(elem* seq_1, elem* seq_2) {
		elem* p = this->begin;
		while (p != NULL) {
			elem* temp1 = p;
			elem* temp2 = seq_1;
			bool isCanBeReplaced = true;
			while (temp1 != NULL && temp2 != NULL) {
				if (temp1->letter == temp2->letter) {
					temp1 = temp1->next;
					temp2 = temp2->next;
				}
				else {
					isCanBeReplaced = false;
					break;
				}
				if (temp1 == NULL && temp2 != NULL) {
					isCanBeReplaced = false;
				}
			}
			if (isCanBeReplaced) {
				elem* temp3 = seq_2;
				while (temp3 != NULL) {
					p->letter = temp3->letter;
					p = p->next;
					temp3 = temp3->next;
				}
			} else{
				p = p->next;
			}
		}
	}
	elem* getbegin() {
		return this->begin;
	}
};
int main()
{
	list_ word;
	char x = 0;
	cout << "enter the word by character: \n";
	while (x != '.') {
		cin >> x;
		word.push_back(x);
	}
	

	list_ sequence_1;
	x = 0;
	cout << "\nenter the old sequence by character: \n";
	while (true) {
		cin >> x;
		if (x == '.') {
			break;
		}
		else {
			sequence_1.push_back(x);
		}
	}
	cout << "sequence 1: "; sequence_1.show();

	list_ sequence_2;
	x = 0;
	cout << "\nenter the new sequence by character: \n";
	while (true) {
		cin >> x;
		if (x == '.') {
			break;
		}
		else {
			sequence_2.push_back(x);
		}
	}
	cout << "sequence 2: "; sequence_2.show();

	cout << "\nbefore\t "; word.show();
	word.replace(sequence_1.getbegin(), sequence_2.getbegin());
	
	cout << "\nafter\t "; word.show();

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
