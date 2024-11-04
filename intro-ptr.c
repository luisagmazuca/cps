#include<stdio.h>
/* write a C program that computes the product of two integers 
(rovided by the user) by calling a function mult*/

int mult(int a, int b){
    return a*b;
}

int main(){
    int gigi, toto;
    printf("Enter two integers: \n");
    scanf("%d %d", &gigi, &toto); //intro to address/location

    printf("Product = %d \n", mult(gigi, toto));
}