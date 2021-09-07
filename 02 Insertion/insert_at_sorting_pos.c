#include <stdio.h>
#include <stdlib.h>

void insert_at_pos(int* arr , int size);/* 0 to n -2 array is  sorted we have to put n-2 unsorted number to correct location*/
void show(int* arr , int size, const char* msg);

int main(){

	int arr1[5] = {12,35,36,46,28};
	int arr2[5] = {10,20,30,40,0};
	
	show(arr1, 5 , "arr 1 before sort");
	insert_at_pos(arr1, 5);
	show(arr1, 5 , "arr 1 After sort");

	show(arr2, 5 , "array 2 before sort");
	insert_at_pos(arr2, 5);
	show(arr2, 5 , "array 2 After sort");


	return (EXIT_SUCCESS);
}

void insert_at_pos(int* arr , int size){
	int i = size - 2;
	int key = arr[size - 1];
	while(i > -1 && arr[i] > key)
	{
		arr[i + 1] = arr[i];
		i--;
	}
	arr[i + 1] = key;
}

void show(int* arr , int size,const char* msg){
	puts(msg);
	for(int i = 0 ; i < size  ; i++)
		printf("%d : [%d]\n", i, arr[i]);
}
