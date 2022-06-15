/*  Command line 
    # insertion_sort.exe nr_elements  
    # ./insertion_sort nr_elements 

    # ./insertion_sort 100 

    The program will allocate array of 100 integers dynamically. 
    The array will be filled up by random numbers 
    The array will be shown before sorting 
    The array will be sorted. 
    The array will be shown after sorting. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXELE (1000000)

void sort(int* arr, int n);
void insert_at_sorting_pos(int* arr, int n);
void insertion_sort(int* arr, int n);
void input(int* arr, int n);
void output(int* arr, int n , char* msg);

int main(int argc, char* argv[]){

	if(argc != 2){
		printf("Usage Err :  app.exe nr_elements \n");
		return 0;
	}

	int n = atoi(argv[1]);

	int * array = (int*)malloc(n * sizeof(int));
	if(array == NULL){
		fprintf(stderr,"out of memmory\n");
		return (EXIT_FAILURE);
	}
	input(array, n);
	output(array, n, "before sort");

	time_t start_time = time(0);
	sort(array , n);
	time_t end_time = time(0); 

	output(array, n, "After sort");	
	printf("Total required time: %lld\n",end_time - start_time );
	return (EXIT_SUCCESS);
}

void sort(int* arr, int n){
	insertion_sort(arr , n);
}

void insert_at_sorting_pos(int* arr, int n){

	int key = arr[n-1];
	int i = n - 2;
	while(i > -1 && arr[i] > key ){
		arr[i + 1] = arr[i];
		i--;
	}
	arr[i+1] = key;
}

void insertion_sort(int* arr, int n){

	if(n < 2 )
		return ;

	for(int j = 2 ; j <= n ; j++){
		insert_at_sorting_pos(arr, j);
	}
}	

void input(int* arr, int n){

	srand(time(0));
	for(int i = 0 ; i < n ; i++)
		arr[i] = rand() % MAXELE;
}

void output(int* arr, int n , char* msg){

	if(msg!="")
		puts(msg);
	for(int  i = 0 ; i < n ; i++ ){
		printf("%d: [%d]\n", i , arr[i]);
	}
}
