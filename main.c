#include <stdio.h>
#include <conio.h>
#include <math.h>
#include "validation.h"
#include "calc.h"
#define to_rad(simpled_x) (simpled_x * M_PI / 180.0)
int main()
{
    char choice = 0;
    double x1 = 0, x2 = 0, dx = 0, epsilon = 0, sin_x1 = 0, sin_x2 = 0, cos_x1 = 0, cos_x2 = 0, x1_rad  = 0, x2_rad  = 0;
    x1 = val_double_input("x1=");
    x2 = val_double_input("x2=");
    dx = val_double_input("dx=");
    epsilon = val_double_input("epsilon=");
    do
    {
        printf("Choose an option(1 - to calculate sin, 2 - to calculate cos):\n");
        choice = scanf("%c", &choice);
        if (choice != 1 && choice != 2)
        {
            printf("Invalid input.\n");
        }
        fflush(stdin);
    }
    while (choice != 1 && choice != 2);
    int m = 0, n = 0;
    float arr[m][n];
    for (double x = x1; x1 < x2 ? x <= x2 : x >= x2; x += dx)
    {
        if (fabs(x) > 360)
        {
            int i = x/360.0;
            double simpled_x = 0;
            simpled_x = x - 360.0*i;

            double x_rad = to_rad(simpled_x); // Переведення в радіани
            double taylor_result = 0, lib_result = 0, diff = 0;

            if (choice == 1)
                taylor_result = taylor_cos(x_rad, epsilon);
            lib_result = cos(x_rad);
            diff = fabs(taylor_result - lib_result);
            printf("  %-6.6lf    %-*.*lf    %-14.14lf    %-10.10lf  \n", x, abs(log10(epsilon)), abs(log10(epsilon)), taylor_result, lib_result, diff);
        }
        else
        {
            double x_rad = to_rad(x); // Переведення в радіани
            double taylor_result = 0, lib_result = 0, diff = 0;

            taylor_result = taylor_cos(x_rad, epsilon);
            lib_result = cos(x_rad);
            diff = fabs(taylor_result - lib_result);
            arr[m][n] = x;
            arr[m+1][n+1] = taylor_result;
            printf("%lf\t%lf\n", arr[m][n], arr[m+1][n+1]);
            n++;
            //printf("  %-6.6lf    %-*.*lf    %-15.15lf    %-15.15lf  \n", x, abs(log10(epsilon)), abs(log10(epsilon)), taylor_result, lib_result, diff);//
        }

    }
}