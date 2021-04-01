#pragma once
#include "SquareRootMethod.h"
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

long double sq(long double a) {
    return a * a;
}
long double sign(long double a) {
    return (a == 0 ? 0 : (a < 0 ? -1 : 1));
}

pair<long double, long double> CalculateSD(const vector<vector<long double>>& A, const vector<vector<long double>>& S, const vector<vector<long double>>& D, int i) {
    long double r = A[i][i];
    for (int p = 0; p <= i - 1; ++p) {
        r -= sq(S[p][i]) * D[p][p];
    }
    return make_pair(sqrt(abs(r)), sign(r));
}

long double CalculateS(const vector<vector<long double>>& A, const vector<vector<long double>>& S, const vector<vector<long double>>& D, int i, int j) {
    long double r = A[i][j];
    for (int p = 0; p <= i - 1; ++p) {
        r -= S[p][i] * D[p][p] * S[p][j];
    }
    return r / (D[i][i] * S[i][i]);
}

vector<long double> SolveFromSTD(const vector<vector<long double>>& S, const vector<vector<long double>>& D, const vector<long double>& b) {
    const int n = S.size();
    vector<long double> x(n);
    for (int i = 0; i < n; ++i) {
        x[i] = b[i];
        for (int j = 0; j < i; ++j) {
            x[i] -= D[j][j] * S[j][i] * x[j];
        }
        x[i] /= D[i][i] * S[i][i];
    }
    return x;
}

vector<long double> SolveFromS(const vector<vector<long double>>& S, const vector<long double>& b) {
    const int n = S.size();
    vector<long double> x(n);
    for (int i = n - 1; i >= 0; --i) {
        x[i] = b[i];
        for (int j = i + 1; j < n; ++j) {
            x[i] -= S[i][j] * x[j];
        }
        x[i] /= S[i][i];
    }
    return x;
}

vector<double long> SquareRootMethod(const vector<vector<long double>>& A, vector<long double>& b) {
    const int n = A.size();
    vector<vector<long double>> S(n, vector<long double>(n)), D(n, vector<long double>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if (i == j) {
                pair<long double, long double> sd = CalculateSD(A, S, D, i);
                S[i][i] = sd.first;
                D[i][i] = sd.second;
            }
            else {
                S[i][j] = CalculateS(A, S, D, i, j);
            }

        }
    }
    vector<long double> y = SolveFromSTD(S, D, b);
    return SolveFromS(S, y);
}

int SquareRootMethodAnswer() {
    vector<vector<long double>> A{ {1, 2, 0},
             {2, 2, 4},
             {0, 4, 3} };
    vector<long double> b{ 5, 22, 20 };
    vector<long double> x = SquareRootMethod(A, b);
    cout << endl <<"---SquareRootMethod---" << endl << endl;
    cout << "System Solutions" << endl;
    int i = 0;
    for (auto el : x) {
        i += 1;
        cout << "x[" << i << "]=" << el << endl;
    }
    return 0;
}
