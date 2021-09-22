#include <stdio.h>

int Search(int * ar, int serch_ele, int start, int end);
void insertion_sort(int* ar ,int n);
void show(int* ar, int n, char* msg);

int main()
{
	int ar[10] = {10, 9, 8 , 7, 6 , 5 , 4 , 3 , 2 , 1};
	
	show(ar,10,"before sort");
	insertion_sort(ar, 10);
	show(ar, 10, "After sort");
	int n;
 	n = Search(ar, 1 , 0 , 9);
	if(n == -1){
		printf("given number not available\n");
		return -1;
	}
	printf("given number is available at Index = %d \n",n);

	return 0;
}

int Search(int * ar, int serch_ele, int start, int end)
{
	int mid;
	if(start <= end)
	{
		mid = (start + end) / 2;
		if(ar[mid] == serch_ele)
			return mid;
		else if(serch_ele < ar[mid])
			return Search(ar, serch_ele, start, mid -1 );
		else if(serch_ele > ar[mid])
			return Search(ar, serch_ele, mid + 1, end);
	}
	return -1;
}

void insertion_sort(int* ar ,int n)
{
	int key , i;
	for(int j = 1 ; j < n ; j++)
	{
		key = ar[j];
		for( i = j - 1 ;  i > -1 && key < ar[i] ; i--)
		{
			ar[i + 1] = ar[i];
		}
		ar[i + 1] = key;
	}
	return ;
}

void show(int* ar, int n, char* msg)
{
	puts(msg);
	for(int i = 0 ; i < n ; i++)
		printf("%d:[%d]\n",i ,ar[i]);
}
