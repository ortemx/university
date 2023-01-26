#include <iostream>
#include <cmath>
#include <iomanip>
#include <windows.h>
#include <ctime>
#include <thread>

using namespace std;

// генераци€ матрицы
template <typename T>
void generate_matrix(T A, int m, int n, int min_value = -20, int max_value = 40){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            A[i][j] = rand() % (max_value + 1)+ min_value;
        }
    }
}

// вывод матрицы
template <typename T>
void printMatrix(T A, int m, int n){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cout << setw(11) << A[i][j]<<"\t";
        }
        printf("\n");
    }
}
// стандартное произведение матриц
void matrix_multiply(int **A, int **B, int **C, int m, int k, int n){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            C[i][j] = 0;
            for (int l = 0; l < k; l++){
                C[i][j] += A[i][l] * B[l][j];
            }
        }
    }
};


// произведение матриц с помощью потоков
void multiplication_using_threads(int** A, int** B, int** C, int n, int k, int m, int tread_count = thread::hardware_concurrency()) {
    thread* treads = new thread[tread_count];
    for (int i = 0; i < tread_count; i++) {
        treads[i] = thread([](int** a,int** b, int** c, int n, int k, int m, int offset, int thread_count){
            for (int i = 0 + offset; i < n; i += thread_count) {
                for (int j = 0; j < m; j++) {
                    c[i][j] = 0;
                    for (int p = 0; p < k; p++){
                        c[i][j] += a[i][p] * b[p][j];
                    }
                }
            }
        }, A, B, C, n, k, m, i, tread_count);
    }
    for (int i = 0; i < tread_count; i++) {
        treads[i].join();
    }
}

// ‘ункци€ получени€ времени
INT64 getTime(LARGE_INTEGER li){
    QueryPerformanceCounter(&li);
    return (li.QuadPart);
}


int testing(int min_dimension, int max_dimension, int dim_difference){
    double PCFreq = 0;
    INT64 start = 0;
    INT64 finish = 0;
    LARGE_INTEGER li;
    QueryPerformanceFrequency(&li);
    PCFreq = double(li.QuadPart) / 1000.0;

    printf("dim      std  2thrds  4thrds  6thrds  8thrds");
    for(int dimension = min_dimension; dimension <= max_dimension; dimension += dim_difference){
        printf("\n%04i ", dimension);

        int **A = new int*[dimension];
        for(int i = 0; i < dimension; i++){
            A[i] = new int[dimension];
        }

        int **B = new int*[dimension];
        for(int i = 0; i < dimension; i++){
            B[i] = new int[dimension];
        }

        int **result_matrix = new int*[dimension];
        for(int i = 0; i < dimension; i++){
            result_matrix[i] = new int[dimension];
        }

        double times[] = {0, 0, 0, 0, 0};

        generate_matrix(A, dimension, dimension);
        generate_matrix(B, dimension, dimension);

        // подсчет времени дл€ разного числа потоков

        // 1 поток
        start = getTime(li);
        matrix_multiply(A, B, result_matrix, dimension, dimension, dimension);
        times[0] = getTime(li) - start;


        // 2 потока
        start = getTime(li);
        multiplication_using_threads(A, B, result_matrix, dimension, dimension, dimension, 2);
        times[1] = getTime(li) - start;

        // 4 потока
        start = getTime(li);
        multiplication_using_threads(A, B, result_matrix, dimension, dimension, dimension, 4);
        times[2] = getTime(li) - start;

        // 6 потоков
        start = getTime(li);
        multiplication_using_threads(A, B, result_matrix, dimension, dimension, dimension, 6);
        times[3] = getTime(li) - start;

        // 8 потоков
        start = getTime(li);
        multiplication_using_threads(A, B, result_matrix, dimension, dimension, dimension, 8);
        times[4] = getTime(li) - start;

        // вывод результатов
        for(int i = 0; i < 5; i++){
            times[i] /= PCFreq;
            printf("%07.1f ",times[i]);
        }

        // освобождение ресурсов
        for (int i = 0; i < dimension; i++){
            delete[]A[i];
            delete[]B[i];
            delete[]result_matrix[i];
        }
        delete[]A;
        delete[]B;
        delete[]result_matrix;
    }

    printf("\nрезультаты готовы\n");
}


int main()
{
    setlocale(0,"Russian");
    setlocale(LC_NUMERIC, "French_Canada.1252");
    srand(time(NULL));

    testing(100, 200, 10);

    system("pause");
    return 0;
}
