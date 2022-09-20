#include <stdio.h>
#include <math.h>

int SolveSq(double a, double b, double c, double *x1, double *x2);

int SolveLin(double a, double b, double *x);

void PrintSol(int n_roots, double x1, double x2);

int main() {
    printf("Hello, this is Ultimate Square Equation Solver - 3000 (USES-3000) by Daniil Timchenko\n");

    int stop = 0;
    char c = 'a';
    
    while (stop!=1) {
        printf("Enter a, b and c coefficients of quadratic equation\n");

        int check=0;
        double a=0, b=0, c=0, x1=0, x2=0;

        check=scanf("%lg %lg %lg", &a, &b, &c);
        while (check!=3) {
            printf("Wrong input. Please try again\n");
            fflush(stdin);
            check=scanf("%lg %lg %lg", &a, &b, &c);
        }

        int n_roots = SolveSq(a, b, c, &x1, &x2);

        PrintSol(n_roots, x1, x2);

        printf("Type 'y' to continue solving or type 'n' to exit program\n");

        fflush(stdin);
        c = getchar();
        while ((c!='y') && (c!='n')) {
            printf("%c", c);
            printf("Wrong input. Please try again\n");
            fflush(stdin);
            c = getchar();
        }

        stop = c=='n' ? 1 : 0;
        
    }

    return 0;
}

int SolveSq(double a, double b, double c, double *x1, double *x2) {

    if ((a==0) && (b==0)) {
        if (c==0) return -1;
        else return 0;
    }

    if (a==0) return SolveLin(b, c, x1);

    if (c==0) {
        *x1=0;
        return SolveLin(a, b, x2)+1;
    }

    double d = b*b - 4*a*c;

    if (d<0) return 0;

    if (d==0) {
        *x1=(-b)/(2*a);
        return 1;
    }

    *x1=(-b-sqrt(d))/(2*a);
    *x2=(-b+sqrt(d))/(2*a);
    return 2;
}

int SolveLin(double a, double b, double *x) {
    *x=(-b)/a;
    return 1;
}

void PrintSol(int n_roots, double x1, double x2) {
    switch (n_roots) {
    case -1: printf("All real numbers are solutions\n"); break;
    case 0: printf("There are no real roots\n"); break;
    case 1: printf("The only root is %lg\n", x1);
    case 2: printf("There are two real roots: %lg and %lg\n", x1, x2); break;
    default: printf("ERROR! DANGER! EXPLOTION IS INEVITABLE!\n");
    }
}