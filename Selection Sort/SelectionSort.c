/*
	Selection Sort...
*/
//Headers
#include <stdio.h>
#include <stdlib.h>

//Function Declartions
void Sort(int* Arr,int n);
void swap(int* Arr_i, int* Arr_min);
void print(int* Arr, int n, char* msg);

//Function Definations
int main(){
	//code
	int i,n;
	printf("Enter the Number of Elements of you want to sort:\n");
	scanf("%d",&n);

	int* Arr = (int*)malloc(n*sizeof(int));
	if(Arr == NULL){
		printf("Dyanamic Memory Alloaction Failed \n");
	}

	printf("Enter The Elememnts :\n");
	for(i = 0 ; i < n ; i++)
		scanf("%d",Arr+i);

	print(Arr, n, "\nBefore Sort :");
	Sort(Arr,n);
	print(Arr, n, "\nAfter Sort : ");

	free(Arr);
	Arr = NULL;
	return 0;
}

void Sort(int* Arr,int n){
	int i,j,min;

	for (int i = 0; i < n; ++i){
		min = i;

		for(j = i+1 ; j < n ; j++){
			if(Arr[j] < Arr[min])
				min = j;
		}

		if(min != i)
			swap(&Arr[i],&Arr[min]);
	}
}

void swap(int* Arr_i, int* Arr_min){
	int temp;

	temp = *Arr_i ;
	*Arr_i = *Arr_min;
	*Arr_min = temp;
}

void print(int* Arr, int n, char* msg){
	puts(msg);
	for(int i = 0 ; i < n ; i++)
		printf("| %d | ",Arr[i]);
}
