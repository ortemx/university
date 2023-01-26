#include <iostream>
#include <cmath>
#include <cstdlib>
#include <windows.h>
#include <tlhelp32.h>
#include <ctime>
#include <iomanip>
#include <fstream>

using namespace std;


void generateMatrix(double** A, int m, int n){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            A[i][j] = rand() % 40 - 20;
        }
    }
}


void generateVector(double* x, int n){
    for (int i = 0; i < n; i++){
        x[i] = rand() % 40 - 20;
    }
}


template <typename T>
void printMatrix(T A, int m, int n){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cout << setw(4) << A[i][j];
        }
        cout<<endl;
    }
}


template <typename T>
void printVector(T A, int n, string mode = "column"){
    for (int i = 0; i < n; i++){
        cout << setw(4) << A[i];
        if (mode == "column"){
            cout<<endl;
        }
    }
}


double * gauss(double **a, double *y, int length, LARGE_INTEGER li, __int64 *start, __int64 *finish) {
    int m = length;
    int n = length;
    double max, tempforswap;
    int k, index;
    const double eps = 0.00001;

    QueryPerformanceCounter(&li);
    *start = li.QuadPart;

    // решалово
    double *x = new double[n];
    k = 0;
    while (k < n) {

    // Поиск строки с максимальным a[i][k]

        max = abs(a[k][k]);
        index = k;

        for (int i = k + 1; i < n; i++) {
            if (abs(a[i][k]) > max) {
                max = abs(a[i][k]);
                index = i;
            }
        }


        // Перестановка строк

        if (max < eps) {

            // нет ненулевых диагональных элементов

            cout << "Решение получить невозможно из-за нулевого столбца ";
            cout << index << " матрицы A" << endl;
            return 0;
        }

        for (int j = 0; j < n; j++) {
            tempforswap = a[k][j];
            a[k][j] = a[index][j];
            a[index][j] = tempforswap;
            //swap(a[k][j], a[index][j]);
        }

        tempforswap = y[k];
        y[k] = y[index];
        y[index] = tempforswap;
        //swap(y[k], y[index]);


        // Нормализация уравнений

        for (int i = k; i < n; i++) {
            double temp = a[i][k];
            if (abs(temp) < eps){
                continue; // для нулевого коэффициента пропустить
            }

            for (int j = 0; j < n; j++){
                a[i][j] /=  temp;
            }

            y[i] /= temp;

            if (i == k){
                continue; // уравнение не вычитать само из себя
            }

            for (int j = 0; j < n; j++){
                a[i][j] -= a[k][j];
            }

            y[i] -= y[k];
        }

        k++;
    }


    // обратная подстановка

    for (k = n - 1; k >= 0; k--) {
        x[k] = y[k];
        for (int i = 0; i < k; i++)
        y[i] -= a[i][k] * x[k];
    }

    QueryPerformanceCounter(&li);
    *finish = li.QuadPart;
    return x;
}

int main(){
    setlocale(0,"Russian");
    srand(time(NULL));

    double PCFreq, time;
    __int64 start = 0;
    __int64 finish = 0;
    LARGE_INTEGER li;

    QueryPerformanceFrequency(&li);
    PCFreq = double(li.QuadPart) / 1000.0;

    for (int i = 10; i <= 1000; i+= 10){
        double** a = new double* [i];
        for (int j = 0; j < i; j += 1){
            a[j] = new double[i];
        }

        double* y = new double[i];
        double* x = new double[i];

        generateMatrix(a, i, i);
        generateVector(y, i);

        //printMatrix(a, i, i);
        //printVector(y, i);

        x = gauss(a, y, i, li, &start, &finish);

        //printVector(x, i);

        time = (finish - start) / PCFreq;
        cout << i << "\t" << time << "\n";

        for (int j = 0; j < i; j++){
            delete[]a[j];
        }
        delete[]a;
        delete[]y;
        delete[]x;
    }
    system("pause");
    return 0;
}
