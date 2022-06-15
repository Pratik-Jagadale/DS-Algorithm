#include <stdio.h>
#include <stdlib.h>

insertion_sort(int* arr , int n){

	int key;
	for(int i = 0 ; i < n ; i++){
		
		int j = i - 1;
		key = arr[i];
		while( j > -1 && arr[j] > key){
			arr[ j + 1] = arr[j];
			j--;
		}
		arr[ j + 1] = key;
	}
}

int main(){

	int arr[10] ={90,80,70,60,50,40,30,10,20,100};
	insertion_sort(arr, 10);

	for(int i = 0 ; i < 10 ; i ++)
		printf("%d : [%d]\n", i , arr[i]);

	return (EXIT_SUCCESS);
}