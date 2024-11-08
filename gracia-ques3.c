#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define SIZE 20
//MEAN
double arr_mean(int arr[], int n){
	double sum = 0.0;
	double mean = 0.0;
	for (int i = 0 ;i < n; ++i){
		sum +=arr[i];
	}
	mean = sum/n;
	return mean;
}

//MODE
int arr_mode(int arr[], int n){
	int arr_freq[n]; //declare an array same length as og array
	int counter = 0; //counts the amount of times it occurs
	for(int i=0; i<n; i++){ //loops over 
		int curr = arr[i];
		for(int j=0; j<n; j++){
			if(arr[j] == curr){
				counter = counter+1;
				arr_freq[j] = counter;
			}
		}
      counter=0;
	}
	//get max value in array of frequencies
	int max = arr_freq[0];
   int whers_max;
	for(int i =0; i<n; i++){
		if(arr_freq[i] >= max){
			max = arr_freq[i];
         whers_max = i;
		}
      //printf("%d \n",arr_freq[i]);
	}
	return arr[whers_max];
}
//SD
int arr_sd(int arr[], int n){
	double array_mean = arr_mean(arr,n);
	double sum = 0.0;
	double std_d;
	double diff;
	for(int i=0; i<n; ++i){
		diff= arr[i]-array_mean;
		sum += (diff*diff);
	}
	std_d = sqrt(sum/n);
	return std_d;
}

int main(){
   int number[SIZE]; 
   int i=0;
   FILE* in_file = fopen("scores-data.txt", "r"); //only open a pre-exisiting file in read mode. 
         
   if (! in_file ){// equivalent to saying if ( in_file == NULL ) 
      printf("oops, file can't be read\n"); 
      exit(-1); 
   } 
   // attempt to read the next line and store 
   // the value in the "number" variable 
   while ( fscanf(in_file, "%d", & number[i] ) == 1 )  { 
      printf("We just read %d\n", number[i]);
      i++; 
   }
   /*for(int i=0; i<SIZE; i++){
      printf("value at i = %d \n", number[i]);
   }*/
   double mn= arr_mean(number, SIZE);
   printf("The mean is = %lf \n", mn);

   int mode = arr_mode(number, SIZE);
   printf("The mode is = %d \n", mode);

   double sd= arr_sd(number, SIZE);
   printf("The SD is = %lf \n", sd);

   return 0;
}
