/*...recursively reverse subarray...*/

#include <stdio.h>

int reverseArr(int* ar,int* reversedArray , int p , int q);
void show(int* ar, int n , char* msg);

int i = 2 ;
int main()
{
	int ar[10] = {0, 0, 3 , 4 , 5 , 6 , 7 , 0 , 0 , 0};
	int reversedArray[10] = {0} ;

	reverseArr(ar, reversedArray, 2 , 6);
	show(reversedArray , 10, "after reverse");

	return 0;
}

int reverseArr(int* ar ,int* reversedArray, int p , int q)
{
	if(q < i)
		return 0;

	reversedArray[p] = ar[q];
	p = p + 1;
	reverseArr(ar, reversedArray, p ,q - 1 );
	return 0;
}

void show(int* ar, int n, char* msg)
{
	puts(msg);
	for(int i = 0 ; i < n ; i++)
		printf("%d:[%d]\n",i ,ar[i]);
}
