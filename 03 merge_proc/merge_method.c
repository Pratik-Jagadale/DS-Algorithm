#include <stdio.h>

int merge(int * ar1, int ar1_size, int* ar2, int ar2_size, int* ar);
void show(int* ar, int n, char* msg);

int main()
{
 	int ar1[5] = {10 , 20 , 30 , 40 , 50};
 	int ar2[3] = {15 , 25 , 35};

 	int merged_ar[8] = {0}; 
 	merge(ar1, 5, ar2, 3, merged_ar);

 	show(merged_ar, 8, "After merge");
 	//free(merged_ar);
 	//merged_ar = NULL;
 	return 0;
}

int merge(int * ar1, int ar1_size, int* ar2, int ar2_size,int* ar)
{
	int ar_size = ar1_size + ar2_size;

	int i = 0 , j = 0 , k = 0;
	for( j = 0;i < ar1_size && k < ar2_size; j++)
	{
		if(ar1[i] <= ar2[k])
		{
			ar[j] = ar1[i];
			i++;
		}
		else
		{
			ar[j] = ar2[k];
			k++;	
		}
	}

	while(i < ar1_size )
	{
		ar[j] = ar1[i];
		i++;
		j++;
	}
 
	while(k < ar2_size )
	{
		ar[j] = ar2[k];
		k++;
		j++;
	}
	return 0;
}

void show(int* ar, int n, char* msg)
{
	puts(msg);
	for(int i = 0 ; i < n ; i++)
		printf("%d:[%d]\n",i ,ar[i]);
}