#include <iostream>
#include <iomanip>
#include <windows.h>
#include <ctime>
using namespace std;
// ������� ������ �������
void PrintMatr(int **mas, int m) {
    for (int i = 0; i<m; i++) {
        for (int j = 0; j<m; j++)
            printf("%4d", mas[i][j]);
        printf("\n");
    }
}
// ��������� ������� ��� i-� ������ � j-�� �������
void GetMatr(int **mas, int **p, int i, int j, int m) {
    int ki, kj, di, dj;
    di = 0;
    for (ki = 0; ki<m - 1; ki++) { // �������� ������� ������
        if (ki == i)
            di = 1;
        dj = 0;
        for (kj = 0; kj<m - 1; kj++) { // �������� ������� �������
            if (kj == j)
                dj = 1;
            p[ki][kj] = mas[ki + di][kj + dj];
        }
    }
}
// ����������� ���������� ������������
int Determinant(int **mas, int m) {
    int i, j, d, k, n;
    int **p;
    p = new int*[m];
    for (i = 0; i<m; i++)
        p[i] = new int[m];
    j = 0; d = 0;
    k = 1; //(-1) � ������� i
    if (m<1)
        cout << "������������ ��������� ����������!";
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
// �������� �������
int main() {
    setlocale( LC_ALL, "rus" );
    srand(time(NULL));
    int m, i, j;
    long long d;

    cout << "������� ����������� ���������� �������: ";
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
    cout << "������������ ������� ����� " << d << endl;
    cout << (float)(clock() - start_time)/1000;
    return 0;
}
