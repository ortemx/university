#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
    FILE *file ;
    const int n = 100;
    char mystring [n];
    file = fopen("file.txt", "a");
    if (file != NULL){
        fputs("new line\n", file);
    } else{
        perror("error");
    }
    fclose (file);

    file = fopen("file.txt", "r");
    if (!feof(file)){
        if (file != NULL){
            fgets(mystring, n, file);
            cout << mystring;
        } else{
            perror("error");
        }
    } else {
        perror("error");
    }

    fclose (file);
    return 0;
}
