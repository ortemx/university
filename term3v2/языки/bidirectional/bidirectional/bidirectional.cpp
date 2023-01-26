// bidirectional.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

struct elem
{
    char letter;
    elem* next;
    elem* prev;
};

class list_ {
private:
    elem* begin;
    elem* end;
public:
    list_() {
        this->begin = NULL;
        this->end = NULL;
    }
    void pushback(char let) {
        elem* temp = new elem;
        temp->letter = let;
        if (this->begin == NULL) {
            temp->next = NULL;
            temp->prev = NULL;
            this->begin = temp;
            this->end = temp;
        }
        else {
            temp->next = NULL;
            temp->prev = this->end;
            this->end->next = temp;
            this->end = temp;
        }
    }
    void show() {
        elem* p = this->begin;
        cout << p->letter;
        p = p->next;
        while (p != NULL) {
            cout << " --->\t" << p->letter ;
            p = p->next;
        }
    }
    void show2() {
        elem* p = this->end;
        cout << p->letter;
        p = p->prev;
        while (p != NULL) {
            cout << " --->\t" << p->letter ;
            p = p->prev;
        }
    }

    bool isExist(char stop) {
        elem* p = this->begin;
        while (p != NULL) {
            if (p->letter == stop) {
                return 1;
            }
            p = p->next;
        }
        return 0;
    }

    elem* getBegin() {
        return this->begin;
    }
    elem* getEnd() {
        return this->end;
    }
};

void itinerary(list_ stops) {
    char start_st, end_st;
    cout << "\nenter start staition: ";
    cin >> start_st;
    cout << "enter end station: ";
    cin >> end_st;
    elem* begin(stops.getBegin());
    elem* end(stops.getEnd());

    if (!stops.isExist(start_st)) {
        cout << "station '" << start_st << "' doesn't exist";
        return;
    }
    else if (!stops.isExist(end_st)) {
        cout << "station '" << end_st << "' doesn't exist";
        return;
    } 
    else if (start_st == end_st) {
        cout << "You are there!";
    }
    else {
        while (begin != NULL && end != NULL) {
            if (begin->letter == start_st) {
                cout << "from " << begin->letter;
                while (begin->letter != end_st) {
                    begin = begin->next;
                    cout << "\ngo to " << begin->letter;
                }
                return;
            } else if (begin->letter == end_st) {
                while (end->letter != start_st) {
                    end = end->prev;
                }
                cout << "from " << end->letter;
                while (end->letter != end_st) {
                    end = end->prev;
                    cout << "\ngo to " << end->letter;                    
                }
                return;
            }
            else {
                begin = begin->next;
            }
        }
    }
}

int main()
{
    list_ stops;
    char x;
    cout << "enter the stops: \n";
    while (true) { cin >> x; if (x == '.') break; else stops.pushback(x); }
    while (true) {
        stops.show();
        cout << "\n"; stops.show2();
        itinerary(stops);
        cout << "\n";
        system("pause");
        system("cls");
    }
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
