#include <stdio.h>
#include <math.h>
#include "nonlinear-solver.h"

#define max_iter 50
#define tol 1e-6

int main(){
    int option; 
    printf("Solve x^6-x-1=0 using: \n");  
    printf("1. Bisection Method \n");  
    printf("2. Newton's Method \n");  
    printf("3. Secant Method \n");
    printf("4. Exit \n" );
    printf("Selection: \n");
    scanf( "%d", &option );
    switch (option){  
        case 1:
            bisection(tol, max_iter);
            break; 
        case 2:
            Newton(max_iter, tol);
            break;
        case 3:
            secant(tol, max_iter);
            break;
        case 4:        
            printf("You've chosen not to solve the function \n");
            break;
        default:            
            printf("Not an option \n");
            break;
    }
}
