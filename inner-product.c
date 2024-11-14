#include<stdio.h>
#include<time.h>
#include<math.h>
#define SIZE 1000000 //1e6
/*
double *x=malloc(sizeof(double)*n) 
double *y=malloc(sizeof(double)*n) 
*/

int main(int argc, char* argv[]){
    clock_t begin, end;
    double time_taken;
    begin =clock();
    /*do work!*/
    //double x[5] = {1., 2., 3., 4., 5.};
    //double y[5] = {1., -1., 1., -1., 1.};
    /* x=((-1)i)  y= ((-1)i+1).*/
    double x[SIZE];
    double y[SIZE];
    for(int i=0; i<SIZE; i++){
        x[i]=pow(-1,i);
        y[i]=pow(-1,(i+1));
    }

    double product;
    for(int i=0; i<SIZE; i++){
        product+= (x[i])*(y[i]);
    }

    end = clock();
    time_taken = ((double)(end-begin))/CLOCKS_PER_SEC;
    printf("Product = %lf \n", product);
    printf("time taken for this code = %f seconds \n", time_taken);

}