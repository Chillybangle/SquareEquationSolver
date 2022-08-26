#include <stdio.h>
#include <math.h>
#include "functions.h"

/*!
 * \brief Shows whether double value is equal to is_zero
 * 
 * Shows whether double value is equal to zero taking 
 * into account the error
 * \param[in] x Double type value
 * \return 1 if value is zero and 0 otherwise
 */
static int is_zero(double x);

enum Roots solve_square (double a, double b, double c, double *x1, double *x2) 
{    
    if (is_zero (a)) {
        return solve_linear (b, c, x1);
    }
    
    double discrim = b * b - 4 * a * c;
    
    //printf ("discrim = %lf\n", discrim);
    if (discrim < 0) {
        return Roots_NOSOLUTION;
        
    } else if (is_zero (discrim)) {
        *x1 = *x2 = (-b / (2 * a));
        return Roots_ONE;
        
    } else {
        double disc_sq = sqrt (discrim);
        *x1 = (-b + disc_sq) / (2 * a);
        *x2 = (-b - disc_sq) / (2 * a);
        return Roots_TWO;
    }
}

enum Roots solve_linear (double b, double c, double *x) 
{
    if (is_zero (b) && !is_zero (c)) {
        return Roots_NOSOLUTION;
        
    } else if (is_zero (b)) {
        return Roots_INFSOLUTIONS;
        
    } else {
        *x = -c / b;
        return Roots_ONE;
    }
}

static int is_zero (double x) 
{
    const double error = 0.001;
    return (fabs (x) < error);
}
