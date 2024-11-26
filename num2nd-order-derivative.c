#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <cblas.h> //change to #include "cblas.h" to run in my mac :)

/*
Usage:
gcc num2nd-order-derivative.c -o 2nd-derv -lm -lblas
./2nd-derv N
*/

void diff(double* u, int N, double dx, double* d2u) {
    for (int i = 1; i <= N - 1; ++i) {
        d2u[i] = (u[i + 1] - 2.0 * u[i] + u[i - 1]) / (dx * dx);
    }
}

void init(double* u, int N, double dx) {
    for (int i = 0; i <= N; ++i) {
        u[i] = sin(i * dx);
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <number of intervals>\n", argv[0]);
        return 1;
    }

    int N = atoi(argv[1]);

    // Allocate arrays
    double* u = (double*)malloc((N + 1) * sizeof(double));
    double* d2u = (double*)malloc((N + 1) * sizeof(double));
    double* errd2u = (double*)malloc((N - 1) * sizeof(double));

    // Define dx for [0, pi]
    double dx = M_PI / N;

    // Initialize function values
    init(u, N, dx);

    // Compute second derivative using central finite differences
    diff(u, N, dx, d2u);

    // Compute error at interior points
    for (int i = 1; i <= N - 1; ++i) {
        double exact = -sin(i * dx); // Exact second derivative of sin(x)
        errd2u[i - 1] = exact - d2u[i];
    }

    // Compute L2 error
    double error_L2 = cblas_ddot(N - 1, errd2u, 1, errd2u, 1);
    error_L2 = sqrt(error_L2);

    // Print L2 error
    printf("L2 error = %f\n", error_L2);

    // Free memory
    free(u);
    free(d2u);
    free(errd2u);

    return 0;
}
