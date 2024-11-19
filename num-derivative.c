#include<stdio.h>
#include <stdlib.h>
#include <math.h>
/*
Approximate the derivative of the function f(x)=sin(x) over the interval [0, 2pi]  using the forward difference formula and central 
difference formula based on a user-defined step size denoted by h.
Note h=(b-a)/N so you can provide N (the number of subintervals instead).Here a=0, b=2pi.
argv[1]=N.
Call this code num_derivative.c
*/
#define PI 3.14159265358979323846
//return f(x)
double f(double x) {
    return sin(x);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s N\n", argv[0]);
        return 1;
    }

    //input
    int N = atoi(argv[1]);
    if (N <= 0) {
        printf("N must be a positive integer.\n");
        return 1;
    }

    //interval
    double a = 0.0;
    double b = 2 * PI;
    double h = (b - a) / N;

    printf("h = %.6f\n", h);

    // Arrays for x and derivatives
    double x[N + 1], forward_diff[N + 1], central_diff[N + 1];

    //initialize values
    for (int i = 0; i <= N; i++) {
        x[i] = a + i * h;
    }

    //forward difference
    for (int i = 0; i < N; i++) {
        forward_diff[i] = (f(x[i + 1]) - f(x[i])) / h;
    }
    forward_diff[N] = NAN; //-> undefined

    //central difference
    central_diff[0] = NAN; //->first point
    for (int i = 1; i < N; i++) {
        central_diff[i] = (f(x[i + 1]) - f(x[i - 1])) / (2 * h);
    }
    central_diff[N] = NAN; //->last point

    printf("x\t\tForward Diff\t\tCentral Diff\n");
    for (int i = 0; i <= N; i++) {
        printf("%.6f\t", x[i]);
        if (i < N) {
            printf("%.6f\t\t", forward_diff[i]);
        } else {
            printf("N/A\t\t");
        }
        if (i > 0 && i < N) {
            printf("%.6f\n", central_diff[i]);
        } else {
            printf("N/A\n");
        }
    }
}