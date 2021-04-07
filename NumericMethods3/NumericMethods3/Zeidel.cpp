#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void Zeidel()
{
    int size = 4;

    vector <vector <long double> > matrix = {
        {5,1,1,0,17},
        {1,2,0,0, 8},
        {1,0,4,2,28},
        {0,0,2,3,23} };

    long double eps = 0.001;

    vector <long double> previousVariableValues(size, 0.0);

    while (true)
    {
        vector <long double> currentVariableValues(size);

        for (int i = 0; i < size; i++)
        {
            currentVariableValues[i] = matrix[i][size];

            for (int j = 0; j < size; j++)
            {
                if (j < i)
                {
                    currentVariableValues[i] -= matrix[i][j] * currentVariableValues[j];
                }

                if (j > i)
                {
                    currentVariableValues[i] -= matrix[i][j] * previousVariableValues[j];
                }
            }

            currentVariableValues[i] /= matrix[i][i];
        }

        long double error = 0.0;

        for (int i = 0; i < size; i++)
        {
            error += abs(currentVariableValues[i] - previousVariableValues[i]);
        }
        if (error < eps)
        {
            break;
        }

        previousVariableValues = currentVariableValues;
    }

    cout << endl << "---Zeidel---" << endl << endl;
    cout << "System Solution:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "x[" << i + 1 << "]= " << previousVariableValues[i] << endl;
    }

}