#include <iostream>
#include <windows.h>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    ifstream stu("students.txt");
    if(!stu){
        cout << "Открыть файл нельзя\n";
        return 0;
    }
    int n;
    stu>>n;

    //student* stud = new student[n];
    string s1,s2;
    int c=0,alg,fiz,hist;
    float s=0;

    for(int i=0;i<n;i++)
    {
        stu>>s1>>s2;
        cout << s1 << " " << s2 << " ";
        stu>>alg;
        stu>>fiz;
        stu>>hist;
        cout << alg << " " << fiz << " "<< hist;
        if(alg==2 || fiz==2 || hist==2){
            c+=1;
            s+=alg+fiz+hist;}
        cout << endl;

    }
    cout<<"Количество неуспевающих студентов: "<<c<<endl;
    cout<<"Средний балл студентов: "<< fixed << setprecision(2)<<s/(c*3);
    stu.close();
    return 0;
}
