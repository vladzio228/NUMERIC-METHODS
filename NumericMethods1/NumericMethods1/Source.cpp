#include "functions.h"

//---------------Relaxsation--------------//
double func1(double x) {
    return x * x * x - 5 * x * x - 4 * x + 20;
}

double deritative1(double x) {
    return 3 * x * x - 10 * x - 4;
}

void relaxsation() {
    double a = -3, b = -1, eps = 1e-3;
    double min, max, t;
    min = deritative1(b);
    max = deritative1(a);
    t = 2 / (min + max);

    double x0 = a, xn;
    double subtraction;

    int i = 1;

    std::cout << i++ << "-th iteration: " << x0 << "  " << func1(x0) << "\n";

    do {
        xn = x0 - t * func1(x0);
        subtraction = fabs(xn - x0);
        x0 = xn;

        std::cout << i++ << "-th iteration: " << xn << "  " << func1(xn) << "\n";
    } while (subtraction > eps);
    std::cout << std::endl;
}

//-----------------Newton-----------------//
double func2(double x)
{
    return x * x * x - 8 * x * x + 9 * x + 18;
}

double deritative2(double x)
{
    return 3 * x * x - 16 * x + 9;
}

double second_deritative2(double x)
{
    return 6 * x - 16;
}

void newton() {
    double a = -2, b = 0, eps = 1e-3;
    double x = a;

    std::cout << "1-th iteration: " << x << "  " << func2(x) << "\n";
    for (int i = 0; std::abs(func2(x)) > eps; ++i) {
        x = x - func2(x) / deritative2(x);
        std::cout << i+2 << "-th iteration: " << x << "  " << func2(x) << "\n";
    }
    std::cout << std::endl;
}

//-----------------Secant-----------------//
double func3(double x)
{
    return x * x * x - 4 * x * x - 15 * x + 18;
}

void secant() {
    double x0 = -5;
    double x1 = -4.5;
    double eps = 1e-3;
    double xn = 0;

    double tmp;
    int i = 1;
    std::cout << i++ << "-th iteration: " << x0 << "  " << func3(x0) << "\n";

    do
    {
        tmp = xn;
        xn = x1 - func3(x1) * (x0 - x1) / (func3(x0) - func3(x1));
        x0 = x1;
        x1 = tmp;
        std::cout << i++ << "-th iteration: " << xn << "  " << func3(xn) << "\n";

    } while (fabs(xn - x1) > eps);
    std::cout << std::endl;
}