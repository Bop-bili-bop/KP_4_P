#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "validation.h"
#include "calc.h"
#define to_rad(x) (x * M_PI / 180.0)
int main()
{
    printf("This program calculates sin/cos from x1 to x2 with step dx\n");
    do
    {
        const size_t size = 4;
        char choice = 0, output_type = 0;
        double x1 = 0, x2 = 0, dx = 0, epsilon = 0;
        char *table_sin[] = {"Degrees", "Taylor_sin", "Table_sin", "Difference"};
        char *table_cos[] = {"Degrees", "Taylor_cos", "Table_cos", "Difference"};
        double array[size] = {};
        x1 = val_double_input("x1=");
        x2 = val_double_input("x2=");
        dx = x1 == x2 ? dx_validation(0) : x1 < x2 ? dx_validation(1) : dx_validation(2);
        epsilon = fabs(val_double_input("epsilon="));
        do
        {
            printf("Choose output type e/d (e for exponent / d for float double)\n");
            output_type = getchar();
            if (output_type != 'e' && output_type != 'd')
            {
                printf("Invalid input.\n");
            }
            fflush(stdin);
        }
        while (output_type != 'e' && output_type != 'd');
        do
        {
            printf("Choose an option (1 - to calculate sin, 2 - to calculate cos):\n");
            choice = getchar();
            if (choice != '1' && choice != '2')
            {
                printf("Invalid input.\n");
            }
            fflush(stdin);
        }
        while (choice != '1' && choice != '2');
        choice == '1'
            ? printf("%-20s %-25s %-25s %-25s\n", table_sin[0], table_sin[1], table_sin[2], table_sin[3])
            : printf("%-20s %-25s %-25s %-25s\n", table_cos[0], table_cos[1], table_cos[2], table_cos[3]);
        for (double x = x1; x1 < x2 ? x <= x2 : x >= x2; x += dx)
        {
            int m = 0;
            double x_rad = fabs(x) > 360 ? to_rad(fmod(x, 2.0 * M_PI)) : to_rad(x);
            double taylor_result = 0, lib_result = 0, diff = 0;
            taylor_result = choice == '1' ? taylor_result = taylor_sin(x_rad, epsilon) : taylor_cos(x_rad, epsilon);
            lib_result = choice == '1' ? sin(x_rad) : cos(x_rad);
            diff = fabs(taylor_result - lib_result);
            array[m] = x;
            array[m + 1] = taylor_result;
            array[m + 2] = lib_result;
            array[m + 3] = diff;
            unsigned decimal_places = fabs(log10(epsilon));
            output_type == 'e'
                ? printf("%-20g %-25.*e %-25e %-25.*e\n", array[m + 0], decimal_places,
                         array[m + 1], array[m + 2], decimal_places, array[m + 3])
                : printf("%-20g %-25.*lf %-25e %-25.*lf\n", array[m + 0], decimal_places,
                         array[m + 1], array[m + 2], decimal_places, array[m + 3]);
            if (dx == 0)
            {
                break;
            }
        }
        printf("Press Q to exit.Any other key to continue...\n");
    }
    while (getchar() != 'Q');
}