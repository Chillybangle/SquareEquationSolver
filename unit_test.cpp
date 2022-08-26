#include "functions.h"
#include <stdio.h>

void unit_test (void) 
{
    double x1 = 0;
    double x2 = 0;
    double mass[][6] = { 
        // a, b, c, x1, x2, nroots
        {1, -3, 0, 0, 3, Roots_TWO},
        {0, 0, 0, 0, 0, Roots_INFSOLUTIONS},
        {0, 1, 1, -1, 0, Roots_ONE},
        {9, 3, 4, 0, 0, Roots_NOSOLUTION},
        {0, 0, 1, 0, 0, Roots_NOSOLUTION}
    };
    
    int ntests = sizeof (mass) / sizeof (mass[0]);
    
    for (int i = 0; i < ntests; i++) 
    {
        int nroots = solve_square (mass[i][0], mass[i][1], mass[i][2], &x1, &x2);
        if (nroots != mass[i][5]) {
            printf ("Неверное количество корней на %d тесте\n", i);
        } else {
            if ((x1 == mass[i][4] && x2 == mass[i][3]) || (x1 == mass[i][3] && x2 == mass[i][4])) {
                printf ("%d - Пройден\n", i);
            } else {
                printf ("Ошибка в решении %d теста.\n\tРезультаты расчета: x1 = %lf x2 = %lf\n"
                        "\tОжидалось: x1 = %lf x2 = %lf\n", 
                        i, x1, x2, mass[i][3], mass[i][4]);
            }
        }
        x1 = x2 = 0;
    }
} 
