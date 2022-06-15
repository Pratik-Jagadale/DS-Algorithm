#include <stdio.h>

void show(int* ar, int n , char* msg);
partition(int* ar, int p, int q);

int main()
{
	int ar[15] = {10,25,30,32,50,60,70,80,45,30,62,80,120,34,50};


	show(ar,15,"before partition:");
	int mid = partition(ar, 0 , 14);
	printf("paratition : %d\n", ar[mid]);
	show(ar,mid ,"left subarray :");
	show(&ar[mid + 1], 14 - mid , "right subarray :");

	return 0;
}

partition(int* ar, int p, int q)
{

	int pivot = ar[q];
	int i = p;
	int tmp;

	for(int j = p ; j < q ; j++)
	{
		if(i == j)
			continue;
		if(ar[j] <= pivot )
		{
			tmp = ar[i];
			ar[i] = ar[j];
			ar[j] = tmp;
			i++;
		}
	}

	ar[q] = ar[ i + 1];
	ar[i + 1] = pivot;

	return  i + 1;
}

void show(int* ar, int n , char* msg)
{
	puts(msg);
	for(int i = 0 ; i < n ; i++)
		printf("%d : [%d]\n", i, ar[i]);
}
