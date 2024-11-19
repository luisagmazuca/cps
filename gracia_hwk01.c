#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX 50

//MODE
void arr_mode(int arr[], int n){
    int arr_freq[n]; //declare an array same length as og array
	int counter = 0; //counts the amount of times it occurs
	for(int i=0; i<n; i++){ //loops over 
		int curr = arr[i]; //keeps track of current value
		for(int j=0; j<n; j++){
			if(arr[j] == curr){
				counter = counter+1; //adds one each time the current # is repeated
				arr_freq[j] = counter;
			}
		}
      counter=0;
	}
	//get max value in array of frequencies
    int max = arr_freq[0];
	for(int i =0; i<n; i++){
		if(arr_freq[i] >= max){
			max = arr_freq[i];
		}
        //printf("%d \n",arr_freq[i]);
	}
    //where values == max, print those
    for(int i=0; i<n; i++){
        if(arr_freq[i] == max){
            printf("The mode is %d \n", arr[i]);
        }
    }
}

int main(){
    int number[MAX]; 
    int count=0;
    FILE* in_file = fopen("data.txt", "r"); 
    if (! in_file ){  
        printf("oops, file can't be read\n"); 
        exit(-1); 
    }
    int create_array[MAX];
    while ( fscanf(in_file, "%d", & number[count] ) == 1 )  { 
      //printf("We just read %d\n", number[i]);
      count++; 
   }

    arr_mode(number, count);
    //printf("The mode is = %d \n", mode);

}