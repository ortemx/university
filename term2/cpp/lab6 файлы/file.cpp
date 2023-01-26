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
        cout << "Файл не открыт";
        return 0;
    }

    int n;
    file >> n;

    //cout << n << endl;
    string s1, s2;
    float S;
    float Sr = 0;
    int alg, pfys, ist;

    for(int i = 0; i < n; i++)
    {
        file >> s1 >> s2;
        cout << s1 << " " << s2 << " ";
        file >> alg;
        file >> pfys;
        file >> ist;
        S = alg + pfys + ist;
        Sr +=S;
        cout << "Средний балл : " << S/3;
        cout << endl;
    }
    cout << "Общий балл всех студентов : " << fixed << setprecision(3) <<  Sr / (n * 3);

    file.close();
    return 0;
}

