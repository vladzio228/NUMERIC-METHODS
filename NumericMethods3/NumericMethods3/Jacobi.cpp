#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

void solve(const vector<float> a,
    const vector<float> b,
    vector<float>& x,
    const float allowed_error)
{
    const unsigned n = x.size();
    vector<float> tmp_x(n);

    float error;

    do
    {
        error = 0;

        tmp_x = b;
        for (unsigned i = 0; i < n; ++i)
        {
            for (unsigned j = 0; j < n; ++j)
            {
                if (i != j)
                {
                    tmp_x[i] -= a[i * n + j] * x[j];
                }
            }

            const float x_updated = tmp_x[i] / a[i * (n + 1)];
            const float e = fabs(x[i] - x_updated);
            x[i] = x_updated;
            if (e > error) { error = e; }
        }
    } while (error > allowed_error);
}

void Jacobi()
{
    setlocale(LC_ALL, "Ukrainian");
    unsigned n = 4;

    vector<float> x(n);
    vector<float> a =
    { 6,3,1,0,
     3,5,0,2,
     1,0,3,1,
     0,2,1,5 };
    vector<float> b = { 25,31,19,35 };

    float allowed_error = 0.001;

    solve(a, b, x, allowed_error);

    cout << "---Jacobi---" << endl << endl;
    cout << "System Solution:" << endl;
    for (unsigned i = 0; i < n; ++i)
    {
        cout << "x[" << i << "]=  " << x[i] << endl;
    }
}