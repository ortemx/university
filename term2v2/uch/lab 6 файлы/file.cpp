#include <iostream>
//#include <ctime>
//#include <stdlib.h>
#include <iomanip>
#include <fstream>
#include <windows.h>
//#include <string>

using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    ifstream file("f.txt");
    if (!file){
        cout << "���� �� ������";
        return 0;
    }

    int n;
    file >> n;

    //cout << n << endl;
    string name, lastname;
    float average = 0;
    int flunk;
    float algebra, physics, history;

    for(int i = 0; i < n; i++)
    {
        flunk = 0;
        file >> lastname >> name;
        cout << lastname << " " << name;
        file >> algebra; if (algebra == 2) flunk++;
        file >> physics; if (physics == 2) flunk++;
        file >> history; if (history == 2) flunk++;
        average += (algebra + physics + history);
        if (flunk){
            cout << " ����� "; cout << flunk; if (flunk == 1) cout << " ������"; else cout << " ������";
        } else {
            cout << " �� ����� �����";
        }
        cout << endl;
    }
    try {
        if (!n)
            throw -1;
        cout << "������� ���� ������ : " << fixed << setprecision(3) << average / (n * 3)<<endl;
    } catch (int){
        cout << "������ ���������� ������� ���� ������. ������� �� 0\n";
    }
    //cout << "������� ���� ������ : " << fixed << setprecision(3) <<  average / (n * 3)<<endl;

    file.close();
    system ("pause");
    return 0;
}

