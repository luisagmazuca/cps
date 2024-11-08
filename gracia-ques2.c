#include<stdio.h>
#include<math.h>
//This program calculates the average of the scores of 5 students.

//MEAN
double arr_mean(int arr[], int n){
	//int n = arr_length(arr); //get length of array
	double sum = 0.0;
	double mean = 0.0;
	for (int i = 0 ;i < 5; ++i){
		sum +=arr[i];
	}
	mean = sum/n;
	return mean;
}
/*MEDIAN
int arr_median(int arr[]){
	int n = arr_length(arr);
	int index = n/2;
	return arr[index];
}*/
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
	//int n = 5;
	//int max_student_size = 1000;
	int x[5];//array of variable length. 
	//x[1]= x[2]= wrong because 
	// indexing begins at 0. x[0] and x[1].
	double avg=-5.0;
	x[0]= 10;
	x[1]= 7;
	x[2]= 5;
	x[3]= 9;
	x[4]= 10;
	double sum = 0.0;//sum 41
	for (int i = 0 ;i < 5; ++i)
		{
		sum +=x[i];
		printf("for i = %d, sum = %lf \n ", i, sum );
			//more for checking if the right sum is being 
			//computed.
		} // for-loop
	avg = sum/5;
	printf("the average score is: %lf \n", avg);

	int n = 5; //array length to call in functions

	double my_mean = arr_mean(x, n);
	printf("The mean is = %lf \n", my_mean);
	/*
	int med = arr_median(x);
	printf("The median is %d \n", med);
	*/

	//CALL MODE
	int mod = arr_mode(x, n);
	printf("The mode is = %d \n", mod);

	//CALL SD
	double my_sd = arr_sd(x, n);
	printf("The SD is = %lf \n", my_sd);
	
}
//ANSWER 2a. -> This code calculates the average of the values in the array of size 5.


