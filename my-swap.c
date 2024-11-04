#include<stdio.h>

void swap(int *ptr2a, int *ptr2b){
    int ptr2temp = *ptr2a;
    *ptr2a =*ptr2b;
    *ptr2b = ptr2temp;
    printf("a = %d \nb = %d \n", *ptr2a, *ptr2b);
}

int main(){
    int val1;
    //int *ptr2val1 = &val1;
   
    int val2;
    //int *ptr2val2 = $val2;

    printf("Enter a value for a \n");
    scanf("%d", &val1);
    printf("Enter a value for b \n");
    scanf("%d", &val2);
    printf("Swap... \n");
    swap(&val1, &val2);
    printf("values after swap a = %d b = %d \n", val1, val2);
}