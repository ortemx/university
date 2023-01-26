#include <iostream>
#include <cmath>
#include <cstdlib>
#include <windows.h>
#include <tlhelp32.h>
#include <ctime>
#include <iomanip>
#include <fstream>

using namespace std;


// Вывод системы уравнений

void sysout(double **a, double *y, int n){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++){
            cout << a[i][j] << "*x" << j;
            if (j < n - 1){
                cout << " + ";
            }
        }
        cout << " = " << y[i] << endl;
    }
}


double * gauss(int *length, LARGE_INTEGER li, __int64 *start, __int64 *finish) {
    int m, n;
    double *x, max, tempforswap;
    int k, index;
    const double eps = 0.00001;

    ifstream streamReader;


    // чтение матрицы А из файла

    streamReader.open("A.txt");
    streamReader >> m;
    streamReader >> n;
    *length = n;

    double **a = new double *[m];
    for(int i = 0; i < m; i++){
        a[i] = new double [n];
        for(int j = 0; j < n; j++){
            streamReader >> a[i][j];
        }
    }

    streamReader.close();


    // чтение вектора b из файла

    streamReader.open("B.txt");
    streamReader >> n;

    double *y = new double[n];
    for(int i = 0; i < n; i++){
        streamReader >> y[i];
    }

    streamReader.close();

    QueryPerformanceCounter(&li);
    *start = li.QuadPart;

    // решалово

    x = new double[n];
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


template <typename T>
void printMatrix(T A, int m, int n){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cout << setw(11) << A[i][j];
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


template <typename T>
void recordVector(T* X, int n, ofstream *streamWriter){
    *streamWriter << n << "\n";
    for (int i = 0; i < n; i++){
        *streamWriter << X[i] << "\n";
    }
}


int main()
{
    setlocale(0,"Russian");
    srand(time( NULL));


    double *x;
    double PCFreq, time;
    __int64 start = 0;
    __int64 finish = 0;
    LARGE_INTEGER li;
    ofstream streamWriter;
    int n;

    QueryPerformanceFrequency(&li);
    PCFreq = (double)(li.QuadPart) / 1000.0;


    x = gauss(&n, li, &start, &finish);

    time = (double)(finish - start) / PCFreq;
    cout << "\nвремя: " << time << "ms\n";


    // запись вектора x в файл

    streamWriter.open("x.txt");
    recordVector(x, n, &streamWriter);
    streamWriter.close();


    // запись результатов в файл

    streamWriter.open("resultsForGauss.txt", ios::app);
    streamWriter << setw(6) << n << setw(10) << time << "ms\n";
    streamWriter.close();

    return 0;
}
