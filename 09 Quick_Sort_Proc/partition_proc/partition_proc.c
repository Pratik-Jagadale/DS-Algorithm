#include <stdio.h>

int partition(int* ar , int p , int q);
void show(int* ar ,int n , char* msg);

int main()
{
	int ar[10] = {23, 25, 63, 3, 4, 9, 35, 11, 33, 15};
	show(ar, 10 , "before partition :");
	int par =partition(ar, 0 , 9);
	show(ar, 10, "after partition :");
	printf("\n%d\n",par );
	return 0;

}

int partition(int* ar , int p , int q)
{
	int pivot = ar[q];
	int tmp = 0;
	int i = p - 1;

	for(int j = p ; j < q ; j++)
	{
		if(ar[j] == ar[i])
		{
			i = i + 1;
			continue;
		}
		else if (ar[j] <= pivot)
		{
			/* code */
			i = i + 1;
			/*swap ar[i] and ar[j] */
			tmp = ar[i];
			ar[i] = ar[j];
			ar[j] = tmp; 
		}
	}

	ar[q] = ar[i + 1];
	ar[i + 1] = pivot;

	return (i + 1);
}

void show(int* ar ,int n , char* msg)
{
	puts(msg);
	for(int i= 0 ; i < n ; i++)
		printf("[%d] ",ar[i] );
}