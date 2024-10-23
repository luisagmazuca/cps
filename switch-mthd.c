#include <stdio.h>
#include <math.h>

//Define the function
double f(double x){
    return pow(x,6)-x-1;  // Function to solve: f(x) = x^6-x-1=0
}

double f_prime(double x) {
    // Derivative of the function to use in Newton's method
    return 6*pow(x,5)-1; //6x^5-1
}

void bisection(double a, double b, double tol, int max_iter){
    printf("This is the solution using the bisection method \n");
    if (f(a) * f(b) >= 0) {
        printf("Incorrect initial interval. The function must have opposite signs at a and b.\n");
        return;
    }

    double func; // variable to evaluate function
    double c = a;  // Initial midpoint

    // Loop for MAX_ITERATIONS or until tolerance is achieved
    for (int i = 0; i < max_iter; i++) {
        // Find the midpoint
        c = (a + b) / 2;

        // Check if the midpoint is the root or if the tolerance level is met
        if (fabs(f(c)) <= tol) { //fabs -> absolute value
            func = f(c);
            printf("Root found: x = %.8f after %d iterations, f(x) = %.8f \n", c, i+1, func);
            return;
        }

        // Print the current state of the midpoint
        //printf("Iteration %d: Midpoint = %.6f\n", i+1, c);

        // Decide which side to continue the process
        if (f(c) * f(a) < 0) {
            b = c;  // Root lies between a and c
        } else {
            a = c;  // Root lies between c and b
        }
    }
    func = f(c);
    printf("Root found after maximum iterations: x = %.8f, f(x) = %lf \n", c, func);
    
}

void Newton(double i_g0, int max_iter, double tol){
    printf("This is the solution using the Newton method \n");

    double func;
    double x = i_g0;
    
    for (int i=0; i<max_iter; i++){
        double f_x = f(x);
        double df_x = f_prime(x);

        if (fabs(df_x) < tol){
            printf("Derivative is too small. Stopping to avoid division by zero. \n");
            return;
        }

        double x_nxt = x - f_x / df_x;
        //printf("Iteration %d: x = %.6f \n", i+1, x_nxt);

        //Check if the current guess is close enough to the root 
        if(fabs(x_nxt - x) < tol){
            func = f(x_nxt);
            printf("Root found: x = %.8f after %d iterations, f(x) = %.8f \n", x_nxt, i+1, func); 
            return;
        }
        x = x_nxt;
         //update for next iteration 
    }
    printf("Method did not converge within %d iterations. Best estimate: x = %.8f \n", max_iter, x);
}

void secant(double i_g0, double i_g1, double tol, int max_iter){
    printf("This is the solution using the secant method \n");
    double g_2;
    double func;
    
    for( int i=0; i < max_iter; i++){
        double f0 = f(i_g0);
        double f1 = f(i_g1);

        //Prevent division by zero
        if(fabs(f1 - f0)< tol){
            printf("Error: Division by zero \n");
            return;
        }
        //secant method formula
        g_2= i_g1 - f1 * (i_g1 - i_g0)/(f1-f0);
        //printf("Iteration %d: x = %lf \n", i+1, g_2);

        //Check if the solution has converged
        if(fabs(g_2 - i_g1) < tol){
            func= f(g_2);
            printf("Root found: x = %.8f after %d iterations, f(x) = %.8f \n", g_2, i+1, func);
            return;
        }

    //update for nxt iteration
    i_g0 = i_g1;
    i_g1 = g_2;
    }
    printf("Root not found within maximum iterations \n");
}

int main(){
    double a = 0;           // Start of interval
    double b = 5;           // End of interval
    double tol = 1e-6;      // Tolerance
    int max_iter = 50;      // Maximum iterations

    double i_g0 = 1;        // Initial guess for Newton and Secant mthds
    double i_g1 = 1.82;        //Initial guess 2  for Secant mthd

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
            bisection(a, b, tol, max_iter);
            break; 
        case 2:
            Newton(i_g0, max_iter, tol);
            break;
        case 3:
            secant(i_g0, i_g1, tol, max_iter);
            break;
        case 4:        
            printf("You've chosen not to solve the function \n");
            break;
        default:            
            printf("Not an option \n");
            break;
    }
    //getchar();
}
