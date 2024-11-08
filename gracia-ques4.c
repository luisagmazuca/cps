#include<stdio.h>
/*Find the max of two integers*/

#define SIZE 10

int main(){
    int nums[10] = {0,1,2,3,10,5,6,19,8,9};
    int *max = nums; //pointer to the first item

    for (int i=0; i< SIZE; ++i){
        if(*(nums + i) >= *max){ //*(nums+1) -> nums[i]
            max = nums + i;
            //printf("max = %d \n", max); //prints adress
        }
    }
    printf("FINAL answer max = %d \n", *max);
}