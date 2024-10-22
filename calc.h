#ifndef FUNC_H
#define FUNC_H
#include <math.h>
#define M_PI 3.14159265358979323846
#define to_degrees(x) (x * 180.0 / M_PI)
double taylor_sin(double x, double epsilon)
{
    double sigma = x, sin = sigma;
    unsigned n = 1;
    do
    {
        sigma *= -x * x / ((n +2)* (n + 1));
        sin += sigma;
        n += 2;
    }
    while (fabs(sigma) > epsilon);
    return sin;
}
double taylor_cos(double x, double epsilon)
{
    double sigma = 1, cos = sigma;
    unsigned n = 1;
    do
    {
        sigma *= -x * x / (2 * n * (2 * n - 1));
        cos += sigma;
        n++;
    }
    while (fabs(sigma) > epsilon);
    return cos;
}
#endif
