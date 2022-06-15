#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
void merge(int* ar, int p, int q, int r);
void show(int* ar, int n, char* msg);
void mergeSort(int* ar, int p, int r);

int main(int argc,char* argv)
{
	int ar[10] = {10 , 20 , 30 , 40 , 50 , 16 , 25 , 35 , 45 , 55};

 	mergeSort(ar, 0, 9);

 	show(ar, 10, "After merge");
 	//free(merged_ar);
 	//merged_ar = NULL;
 	return 0;
} 


void mergeSort(int* ar, int p, int r)
{
	int q ;

	if(p < r)
	{
		q = (p + r) / 2;
		mergeSort(ar, p , q);
		mergeSort(ar, q + 1 , r);
		merge( ar, p , q , r);
	}

}

void merge(int* ar, int p, int q, int r)
{
	int * pa1 = NULL;
	int* pa2 = NULL;
	int n1;
	int n2;
	int i;
	int j;
	int k;
	int cnt;

	n1 = q - p + 1;
	n2 = r - q;

	pa1 = (int*)malloc(n1 * sizeof(int));
	if(pa1 == NULL)
	{
		fprintf(stderr, "out of memmory n1:  %d\n",n1 );
		return ;
	}

	memset(pa1, 0 , n1 * sizeof(int));

	pa2 = (int*)malloc(n2 * sizeof(int));
	if(pa2 == NULL)
	{
		fprintf(stderr , "outof memmory n2 : %d " , n2);
		return ;
	}

	memset(pa2, 0, n2 * sizeof(int));

	for(cnt = 0 ; cnt < n1 ; cnt++)
	{
		pa1[cnt] = ar[p + cnt];
	}

	for(cnt = 0 ; cnt  < n2 ; cnt++)
	{
		pa2[cnt] = ar[q + 1 + cnt];
	}

	i = 0;
	j = 0;
	k = 0;

	while(1)
	{
		if(pa1[i] <= pa2[j])
		{
			ar[p+k] = pa1[i];
			i++;
			k++;
			if( i == n1)
			{
				while(j < n2)
				{
					ar[p + k] = pa2[j];
					j++;
					k++;
				}
				break;
			}
		}
		else
		{
			ar[p + k] = pa2[j];
			k++;
			j++;
			if(j == n2 )
			{
				while(i < n1)
				{
					ar[p +k] = pa1[i];
					k++;
					i++;
				}
				break;
			}

		}
	}

	free(pa1);
	pa1 = NULL;

	free(pa2);
	pa2 = NULL;
}


void show(int* ar, int n, char* msg)
{
	puts(msg);
	for(int i = 0 ; i < n ; i++ )
		printf("%d : [ %d ]\n", i, ar[i]);
}
