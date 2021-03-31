#include <iostream>
#include "ModifiedGauss.h"
using namespace std;

const int N = 4;
int i, j, m, k;
double aa, bb;

double a[N][N + 1] = {
{ 4, 3, 1, 0, 29},   //Матриця коефіцієнтів, де останній стовбець - права частина системи
{-2, 2, 6, 1, 38},
{ 0, 5, 2, 3, 48},
{ 0, 1, 2, 7, 56}
};

void ModifiedGauss() {
    double* x;
    x = (double*)malloc(N * sizeof(double));

    for (k = 0; k < N; k++) //Пошук максимального елемента по модулю в першому стовбці
    {
        aa = abs(a[k][k]);
        i = k;
        for (m = k + 1; m < N; m++)
            if (abs(a[m][k]) > aa)
            {
                i = m;
                aa = abs(a[m][k]);
            }

        if (aa == 0)   //Перевірка на нульовий елемент
        {
            cout << "System has not solutions" << endl;
        }

        if (i != k)  //Перестановка i-ого рядка, той що містить головний елемент k-ого рядка
        {
            for (j = k; j < N + 1; j++)
            {
                bb = a[k][j];
                a[k][j] = a[i][j];
                a[i][j] = bb;
            }
        }
        aa = a[k][k];//Перетворення k-ого рядка (Обчислення масштабуючих множників)
        a[k][k] = 1;
        for (j = k + 1; j < N + 1; j++)
            a[k][j] = a[k][j] / aa;
        for (i = k + 1; i < N; i++)//Перетворення рядків за допомогою k-ого рядка
        {
            bb = a[i][k];
            a[i][k] = 0;
            if (bb != 0)
                for (j = k + 1; j < N + 1; j++)
                    a[i][j] = a[i][j] - bb * a[k][j];
        }
    }

    for (i = N - 1; i >= 0; i--)   //Знаходження розв'язків СЛАУ
    {
        x[i] = 0;
        aa = a[i][N];
        for (j = N; j > i; j--)
            aa = aa - a[i][j] * x[j];
        x[i] = aa;
    }

    cout << "---ModifiedGauss---" << endl << endl;;
    cout << "System Solution:" << endl;  //Виведення розв'язків
    for (i = 0; i < N; i++)
    {
        cout << "x[" << i + 1 << "]=" << x[i];
        cout << endl;
    }
}