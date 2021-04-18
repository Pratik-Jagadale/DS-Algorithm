/*
*	Insertion Sort...
*/

#include <stdio.h>
#include <stdlib.h>

void Sort(int* Arr, int n);
void show(int* Arr, int n,char* msg);

int main(){
	int n,i;
	printf("Enter the count of array \n");
	scanf("%d",&n);

	int* Arr = (int*)malloc(n*sizeof(int));
	if(Arr == NULL){
		printf("Dyanamic Memory Alloaction Failed \n");
	}

	printf("Insert Array :\n");
	for(i = 0 ; i < n ; i++){
		scanf("%d",Arr+i);
	}

	show(Arr,n,"\n Before Sort :");
	Sort(Arr,n);
	show(Arr,n,"\n After Sort :");

	free(Arr);
	return 0;
}

void Sort(int* Arr, int n){
	int i,j,temp;

	for(i = 1 ; i < n ; i++){
		temp = Arr[i];
		j = i - 1;
		while(j >= 0 && Arr[j] > temp){
			Arr[j+1] = Arr[j];
			j--;
		}
		Arr[j + 1] = temp;
	}
}

void show(int* Arr, int n,char* msg){
	puts(msg);
	int i;
	for(i = 0 ; i < n ; i++){
		printf("| %d |" ,Arr[i]);
	}
}
