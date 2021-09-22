#include <stdio.h>

int reverseArr(int* ar,int* reversedArray , int n);
void show(int* ar, int n , char* msg);

int i = 0;

int main()
{
	int ar[10] = {1, 2, 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10};
	int reversedArray[10] = {0};

	reverseArr(ar, reversedArray, 9);
	show(reversedArray , 10, "after reverse");

	return 0;
}

int reverseArr(int* ar ,int* reversedArray, int n){

	if(n < 0)
		return 0;

	reversedArray[i] = ar[n];
	i = i + 1;
	reverseArr(ar, reversedArray,n - 1);
	return 0;
}

void show(int* ar, int n, char* msg)
{
	puts(msg);
	for(int i = 0 ; i < n ; i++)
		printf("%d:[%d]\n",i ,ar[i]);
}
