#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include"Quick_Sort.h"
int CharArrtoint(char *);  //declaration of function of converting character array to integer value

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int partition(int Arr[], int low, int high) {

	int i = low;
	int j = high;
	int pivot = Arr[low];
	
	while(i < j)
	{
		while(Arr[i] <= pivot)
		{
			i++;
		}
		while(Arr[j] > pivot)
		{
			j--;
		}
	
		if(i < j)
		{
			swap(&Arr[i],&Arr[j]);
		}
	}
	Arr[low] = Arr[j];
	Arr[j] = pivot;
	return j;
}

void quickSort(int array[], int low, int high) {
  if (low < high) {
    
    int pi = partition(array, low, high);
    
    quickSort(array, low, pi - 1);
    
    quickSort(array, pi + 1, high);
  }
}


int CharArrtoint(char *Arr){
	
	char c;
	int num=0,temp = 0,i = 0,incr = 1;
	while(Arr[i] != '\0'){
		c =Arr[i];

	switch (c)
	{ 
		case '0':
			temp = 0;
			break;
		case '1':
			temp = 1;
			break;
		case '2':
			temp = 2;
			break;
		case '3':
			temp = 3;
			break;
		case '4':
			temp = 4;
			break;
		case '5':
			temp = 5;
			break;
		case '6':
			temp = 6;		
			break;
		case '7':
			temp = 7;
			break;
		case '8':
			temp = 8;
			break;
		case '9':
			temp = 9;
			break;
		default:
			printf("Error\n");	
	}
	i++;
	num = (num * incr) + temp;	
	incr = incr * 10;
     }
	return num;
}

