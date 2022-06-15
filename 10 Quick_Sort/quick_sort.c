#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void input(int* pa, int n);
void output(int* pa, int n, const char* msg);
int partition(int* pa, int p, int r);
int quick_sort(int* pa, int p, int r);
void  sort(int* pa, int n);

int main(int argc, char* argv[])
{
	int* pa = NULL;
	int size = 0;

	if(argc != 2)
	{
		printf("Enter valid command line argumnets:\n");
		return -1;
	}

	size = atoi(argv[1]);
	pa = (int*)malloc(size * sizeof(int) );

	if(pa == NULL)
	{
		printf("out of memory \n");
		return -1;
	}

	input(pa, size);

	if(size < 100)
		output(pa, size, "before sort");

	sort(pa, size);

	output(pa, size, "After Sort: ");

	return 0;
}

void  sort(int* pa, int n)
{
	quick_sort(pa, 0, n - 1);
}

int quick_sort(int* pa, int p, int r)
{
	int q;
	if(p < r)
	{
		q = partition(pa, p ,r);
		quick_sort(pa, p, q - 1);
		quick_sort(pa, q+ 1 ,r);
	}
	return 0;
}

int partition(int* pa, int p, int r)
{
	int i , j; /*for iteration*/
	int tmp ; /*for exchange elements*/
	int pivot; /*for compare elemnets*/
	pivot = pa[r]; /* last element is the pivot element*/

	i = p - 1  ;

	for(j = p ; j < r ;j++)
	{
		if(pa[j]<=pivot)
		{
			i++;
			tmp = pa[i];
			pa[i] = pa[j];
			pa[j] = tmp;
		}
	}

	tmp = pa[i + 1];
	pa[i + 1] = pa[r];
	pa[r] = tmp;

	return (i + 1);
}

void input(int* pa, int n)
{
	int i ;
	srand(time(0));

	for(i = 0 ; i < n ; i++)
		pa[i] = rand() % 100000;
}

void output(int* pa, int n, const char* msg)
{
	if(msg)
		puts(msg);
	for(int i = 0 ; i < n  ; i++)
		printf("a[%d] : %d \n" , i , pa[i]);
}
