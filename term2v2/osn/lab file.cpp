#include <iostream>
#include <iomanip>
#include <fstream>
#include <windows.h>
#include <string>
#include <cstdio>

using namespace std;

struct students{
    short group;
    char lastname[20];
    short exam[5];
    bool credit[5];
};

void dolg(students * st, int n){
    int c;
    for(int i = 0; i < n; i++){
        c = 0;
        for (int j = 0; j < 5; j++){
            if (st[i].exam[j] == 2)
                c++;
            if (st[i].credit[j] == 0)
                c++;
        }
        if (c){
            cout << st[i].group << " " << st[i].lastname << " " << c <<"\n";
        }
    }
}

void average (students * st, int n){
    short group;
    double average_student;
    double average_group;
    short k = 0;
    cout << "enter group : ";
    cin >> group;
    for (int i = 0; i < n; i++){
        if (group == st[i].group){
            average_student = 0;
            k++;
            for (int j = 0; j < 5; j++){
                average_student += st[i].exam[j];
            }
            average_student /= 5;
            cout << st[i].lastname << " : " << average_student  << "\n";
            average_group += average_student;
        }
    }
    cout << group << " : " << average_group / k;

}

void create(students * st, int n){
    ofstream fout("students.bin", ios::binary);
    for (int i = 0; i < n; i++){
        cout << "Group : "; cin >> st[i].group;
        cout << "Lastname : "; cin >> st[i].lastname;
        for (int j = 0; j < 5; j++){
            //cout << j+1 << " exam grades : ";
            st[i].exam[j] = 2 + rand() % 4;
            //cin >> st[i].exam[j];
        }
        for (int j = 0; j < 5; j++){
            //cout << j+1 << " credit gradess : ";
            st[i].credit[j] = rand() % 100 > 90 ? 0 : 1 ;
            //cin >> st[i].credit[j];
        }
        fout.write((char*)&st[i].group, 10);
        fout.write((char*)&st[i].lastname, 10);
        for (int j = 0; j < 5; j++){
            fout.write((char*)&st[i].exam[j],10);
        }
        for (int j = 0; j < 5; j++){
            fout.write((char*)&st[i].credit[j],10);
        }
    }
    fout.close();
}

void opendata(students * st, int n){
    ifstream fin("students.bin", ios::binary);
    cout <<  "group |" << setw(13) <<"lastname |" << setw(14) <<"exam grades |" << setw(15) <<"credit grades\n";
    for (int i = 0; i < n; i++){
        fin.read((char*)&st[i].group, 10);
        fin.read((char*)&st[i].lastname, 10);

        for(int j = 0; j < 5; j++){
            fin.read((char*)&st[i].exam[j],10);
        }
        for (int j = 0; j < 5; j++){
            fin.read((char*)&st[i].credit[j],10);
        }

        cout << setw(5) << st[i].group <<  " | " << setw(10) << st[i].lastname << " |  ";
        for(int j = 0; j < 5; j++){
            cout <<setw(2) << st[i].exam[j] ;
        }
        cout << " |    ";
        for (int j = 0; j < 5; j++){
            cout <<setw(2) << st[i].credit[j]  ;
        }
        cout <<  "\n";
    }
}

int main(){
    const int n = 10;
    students * st = new students[n];
    //create(st, n);
    //opendata(st, n);

    int key = 1;
    while ( key != 0 ){
        cout << "\n1 : create \n2 : open \n3 : spisok doljnikov \n4 : average score\n";
        cin >> key;
        if (key == 1) create(st, n);
        else if (key == 2) opendata(st, n);
        else if (key == 3) dolg(st, n);
        else if (key == 4) average(st, n);
        else if (key == 0) break;
    }


    return 0;
}
