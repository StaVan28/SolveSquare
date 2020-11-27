/*
#Solve square equation
#Starchenko Ivan, v.2
*/

#include <stdio.h>
#include <math.h>

//-----------------------------------------------------------------------------

#define ERROR    1e-5
#define INFINITY -1

//-----------------------------------------------------------------------------

    int  SolveSquare(double a,double b,double c, double* x1, double* x2);
    int  SolveLine  (double b,double c,double* x1);
    bool CompareZero(double border);

//-----------------------------------------------------------------------------

int main()
    {

    int    NRoots = 0;
    double a = 0, b = 0, c = 0;
    double x1 = 0, x2 = 0;

    printf("Input coeff of square equation: ");
    scanf("%lf %lf %lf", &a, &b, &c);
    NRoots = SolveSquare(a, b, c, &x1, &x2);

    switch(NRoots)
        {
        case 2:
            printf("Your roots: %.2lf, %.2lf", x1, x2);
            break;
        case 1:
            printf("Your root: %.2lf", x1);
            break;
        case 0:
            printf("Sorry, this equation haven't roots");
            break;
        case INFINITY:
            printf("This equation have infinity roots");
            break;
        }

    }

//-----------------------------------------------------------------------------

int SolveSquare(double a,double b,double c,double* x1,double* x2)
    {

    int NRoots = 0;

    if(CompareZero(a))
        {
        NRoots = SolveLine(b, c, x1);
        switch(NRoots)                /**/
            {                         /**/
            case 1:                   /**/
                return 1;             /**/
            case 0:                   /**/
                return 0;             /**/
            case INFINITY:            /**/
                return INFINITY;      /**/
            }                         /**/
        }

    double discr = b*b - 4*a*c;

    if(discr > 0)
        {
        *x1 = (-b + sqrt(discr)) / (2*a);
        *x2 = (-b - sqrt(discr)) / (2*a);
        return 2;
        }

    if(CompareZero(discr))
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
    if(CompareZero(c))
        if(CompareZero(b))
            {
            return INFINITY;
            }
        else
            {
            *x1 = 0;
            return 1;
            }

    if(CompareZero(b))
        return 0;

    *x1 = (-c) / b;
        return 1;
    }

//-----------------------------------------------------------------------------

bool CompareZero(double border)
    {
    if (border <= ERROR)
        return 1;
    else
        return 0;
    }

//-----------------------------------------------------------------------------




