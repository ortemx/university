#include <iostream>
#include <iomanip>
#include <windows.h>
#include <ctime>
using namespace std;
// Функция вывода матрицы
void PrintMatr(int **mas, int m) {
    for (int i = 0; i<m; i++) {
        for (int j = 0; j<m; j++)
            printf("%4d", mas[i][j]);
        printf("\n");
    }
}
// Получение матрицы без i-й строки и j-го столбца
void GetMatr(int **mas, int **p, int i, int j, int m) {
    int ki, kj, di, dj;
    di = 0;
    for (ki = 0; ki<m - 1; ki++) { // проверка индекса строки
        if (ki == i)
            di = 1;
        dj = 0;
        for (kj = 0; kj<m - 1; kj++) { // проверка индекса столбца
            if (kj == j)
                dj = 1;
            p[ki][kj] = mas[ki + di][kj + dj];
        }
    }
}
// Рекурсивное вычисление определителя
int Determinant(int **mas, int m) {
    int i, j, d, k, n;
    int **p;
    p = new int*[m];
    for (i = 0; i<m; i++)
        p[i] = new int[m];
    j = 0; d = 0;
    k = 1; //(-1) в степени i
    if (m<1)
        cout << "Определитель вычислить невозможно!";
    if (m == 1) {
        d = mas[0][0];
    } else if (m == 2) {
        d = mas[0][0] * mas[1][1] - (mas[1][0] * mas[0][1]);
    } else if (m>2) {
        for (i = 0; i<m; i++) {
            GetMatr(mas, p, i, 0, m);
            d = d + k * mas[i][0] * Determinant(p, --m);
            k = -k;
        }
    }
    return(d);
}
// Основная функция
int main() {
    setlocale( LC_ALL, "rus" );
    srand(time(NULL));
    int m, i, j;
    long long d;

    cout << "Введите размерность квадратной матрицы: ";
    cin >> m;

    int **mas = new int*[m];
    for (i = 0; i<m; i++)
        mas[i] = new int[m];

    for (i = 0; i<m; i++)
        for (j = 0; j<m; j++)
            mas[i][j] = -20 + rand()%50;

    PrintMatr(mas, m);
    int start_time =  clock();
    d = Determinant(mas, m);
    cout << "Определитель матрицы равен " << d << endl;
    cout << (float)(clock() - start_time)/1000;
    return 0;
}
