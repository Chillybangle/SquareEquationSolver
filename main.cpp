#include <stdio.h>
#include <math.h>
#include "functions.h"

#define DEBUG 0

int main () 
{
    double a = 0; 
    double b = 0;
    double c = 0;
    double x1 = 0;
    double x2 = 0;
    Roots nroots = Roots_DEFAULT;
    
#if DEBUG == 0
    int input_option = Options_default; //< Shows input option
    while ((input_option = input (&a, &b, &c)))
    {
        switch (input_option)
        {
            case Options_default:
                nroots = solve_square (a, b, c, &x1, &x2);
                output (nroots, x1, x2);
                break;
                
            case Options_meow:
                purr_paint ();
                break;
                
            case Options_help:
                help_desk ();
                break;
                
            default:
                printf ("Unknown fail. Shit happens. Try again\n");
                break;
        }
    }
#else 
    unit_test ();
#endif
    
    return 0;
}
