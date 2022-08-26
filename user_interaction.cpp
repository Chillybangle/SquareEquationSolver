#include "functions.h"
#include <stdio.h>

//! Clear the input from wrong chars
static void inp_clearing (void);

void output (enum Roots nroots, double x1, double x2) 
{
    switch (nroots) 
    {
        case Roots_NOSOLUTION:
            printf ("\nНет решения\n");
            break;
            
        case Roots_INFSOLUTIONS:
            printf ("\nБесконечно решений\n");
            break;
            
        case Roots_TWO:
            printf ("\nx1 = %lf x2 = %lf \n", x1, x2);
            break;
            
        case Roots_ONE:
            printf ("\nx = %lf \n", x1);
            break;
            
        default:
            printf ("\nUnknown fail. Передано неверное количество корней\n");
            break;
    }
}

int input (double *a, double *b, double *c) 
{
    printf ("---------------------\n");
    printf ("Решает уравнение вида:\n");
    printf ("\t\t\tax^2 + bx + c = 0\n");
    printf ("\nВведите параметры a, b, c через пробел:\n");

    char symb = 'n';//nothing
    while (scanf ("%lf %lf %lf", a, b, c) != 3) 
    {
        switch (symb = getchar ())
        {
            case 'q':
                return Options_quit;
                break;
                
            case 'h':
                return Options_help;
                break;
                
            case 'm':
                return Options_meow;
                break;
                
            default:
                printf ("Неверный ввод! Введите три числа через пробел"
                        "или h для получения справки\n");
                break;
        }
        inp_clearing ();
    }
    
    return Options_default;
}

static void inp_clearing (void)
{
    while (getchar() != '\n')
            ;
}

void purr_paint (void)
{
    printf (
"    /\\___/\\ \n"
"   /       \\ \n"
"  l  u   u  l \n"
"--l----*----l--\n"
"   \\   w   /     - Meow!\n"
"     ======\n"
"   /       \\ __\n"
"   l        l\\ \\ \n"
"   l        l/ / \n"
"   l  l l   l / \n"
"   \\ ml lm /_/ \n"
            );
}

void help_desk (void) 
{
    printf ("\t___HELP DESK___\n");
    printf ("Input:\n\tthree numbers to solve the equation\n");
    printf ("\tq to quit\n");
    printf ("\tm to see a cat\n");
    printf ("\th to see this message\n");
}
