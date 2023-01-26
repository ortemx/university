#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <stdio.h>
#include <windows.h>
#include <ctime>
#include <algorithm>
using namespace std;

struct student{
    string name;
    string lastname;
    string patronymic;
    short group;
    double average;
    int IPF;
};
int main(){
    srand(time(NULL));
    int salary = 18000;
    string student_name = "student_name";
    string student_lastname = "student_lastname";
    string student_patronymic = "student_patronymic";
    stringstream sstream;
    student * students = new student[10];
    for (int i = 0; i < 10; i++){
        sstream << student_name; sstream << i; sstream >> students[i].name; sstream.clear();
        //cout << students[i].name << "\n";
        sstream << student_lastname; sstream << i; sstream >> students[i].lastname; sstream.clear();
        //cout << students[i].lastname << "\n";
        sstream << student_patronymic; sstream << i; sstream >> students[i].patronymic; sstream.clear();
        //cout << students[i].patronymic << "\n";
        students[i].group = 100 + rand() % 5;
        //cout << students[i].group << "\n";
        students[i].average = 3 + (double)(rand() % 10)/5;
        cout << i << " " << students[i].average << "\n";
        students[i].IPF = 30000 + (rand() % 10000);
        cout << i << " " << students[i].IPF << "\n";
    }
    student temp;
    for (int i = 0; i < 10; i++){
        for (int j = i; j < 10; j++){
            if (students[j].IPF < students[i].IPF){
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
    for (int i = 0; i < 10; i++){
        cout << i << " " << students[i].average << "\n";
        cout << i << " " << students[i].IPF << "\n";
    }
    for (int i = 0; i < 10; i++){
        for (int j = i; j < 10; j++){
            if (students[j].IPF < salary * 2){
                if (students[j].average > students[i].average){
                    temp = students[i];
                    students[i] = students[j];
                    students[j] = temp;
                }
                //temp = students[i];
                //students[i] = students[j];
                //students[j] = temp;
            }
        }
    }
    for (int i = 0; i < 10; i++){
        cout << i << " " << students[i].average << "\n";
        cout << i << " " << students[i].IPF << "\n";
    }
    return 0;
}
