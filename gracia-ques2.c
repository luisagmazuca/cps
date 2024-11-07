#include<stdio.h>
#include<math.h>
//This program calculates the average of the scores of 5 students.

int arr_length(int arr[]){
	int i;
	int count = 0;
	for(i=0; arr[i] != '\0'; i++){
		count++;
	}
	return count;
}
//MEAN
double arr_mean(int arr[]){
	int n = arr_length(arr); //get length of array
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
int arr_mode(int arr[]){
	int n = arr_length(arr); //get length of array
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
	}
	//get max value in array of frequencies
	int max = arr[0];
	for(int i =0; i<n; i++){
		if(arr[i] >= max){
			max = arr[i];
		}
	}
	return max;
}
//SD
int arr_sd(int arr[]){
	int n = arr_length(arr); //get length of array
	double sum = 0.0;
	double array_mean = arr_mean(arr);
	double std_d = 0.0;
	double diff = 0.0;
	for(int i=0; i<n; i++){
		diff= (arr[i]-array_mean);
		sum += (diff*diff);
	}
	std_d = (sum)/n;
	std_d = sqrt(std_d);

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

	//int n = arr_length(x);
	//printf("length of array is = %d \n", n);
	double my_mean = arr_mean(x);
	printf("The mean is = %lf \n", my_mean);
	/*
	int med = arr_median(x);
	printf("The median is %d \n", med);
	*/

	//CALL MODE
	int mod = arr_mode(x);
	printf("The mode is = %d \n", mod);

	//CALL SD
	double my_sd = arr_sd(x);
	printf("The SD is = %lf \n", my_sd);
	
}
//ANSWER 2a. -> This code calculates the average of the values in the array of size 5.

//2b.
/*MEAN
CALCULATE SIZE OF THE ARRAY
int arr_size;
arr_size = x.size().
printf("size is = %d \n", arr_size);
*/



//MODE

