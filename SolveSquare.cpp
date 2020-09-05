/*
#Solve square equation
#Starchenko Ivan, v.1
*/

#include <stdio.h>
#include <math.h>

//-----------------------------------------------------------------------------

    int SolveSquare(double a,double b,double c, double* x1, double* x2);
    int SolveLine  (double b,double c,double* x1);
    bool ComperZero(double border);

//-----------------------------------------------------------------------------

int main()
    {

    int    NRoots;
    double a, b, c;
    double x1, x2;

    printf("Input coeff of square equation: ");
    scanf("%lf %lf %lf", &a, &b, &c);
    NRoots = SolveSquare(a, b, c, &x1, &x2);

    if(NRoots ==  2)
         printf("Your roots: %.2lf, %.2lf", x1, x2);
    if(NRoots ==  1)
         printf("Your root: %.2lf", x1);
    if(NRoots ==  0)
         printf("Sorry, this equation haven't roots");
    if(NRoots == -1)
         printf("This equation have infinity roots");

    }

//-----------------------------------------------------------------------------

int SolveSquare(double a,double b,double c,double* x1,double* x2)
    {

    int    NRoots;
    double discr   = b*b - 4*a*c;

    if(ComperZero(a))
        {
        NRoots = SolveLine(b, c, x1);
        }

    if(discr > 0)
        {
        *x1 = (-b + sqrt(discr)) / (2*a);
        *x2 = (-b - sqrt(discr)) / (2*a);
        return 2;
        }

    if(ComperZero(discr))
        {
        *x1 = (-b / (2*a));
        return 1;
        }

    if(discr < 0)
        return 0;
    }

//-----------------------------------------------------------------------------

int SolveLine(double b,double c,double *x1)
    {
    if(ComperZero(c))
        if(
        ComperZero(b))
            {
            return -1;
            }
        else
            {
            *x1 = 0;
            return 1;
            }

    if(ComperZero(b))
        return 0;

    *x1 = (-c) / b;
        return 1;
    }

//-----------------------------------------------------------------------------

bool ComperZero(double border)
    {
    if (border <= 1e-5)
        return 1;
    else
        return 0;
    }

//-----------------------------------------------------------------------------




