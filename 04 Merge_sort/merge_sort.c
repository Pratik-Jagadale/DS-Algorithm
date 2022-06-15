#include <stdio.h>
#include <stdlib.h>
#include <assert.h> 
#include <time.h> 

void merge(int* ar, int p, int q, int r);
void show(int* ar, int n, char* msg);
void MergeSort(int* ar, int start, int end);

int main(int argc,char* argv)
{
	int ar[10] = {10 , 20 , 30 , 40 , 50 , 16 , 25 , 35 , 45 , 55};

 	MergeSort(ar, 0, 9);

 	show(ar, 9, "After merge");
 	//free(merged_ar);
 	//merged_ar = NULL;
 	return 0;
} 

void MergeSort(int* ar, int start, int end)
{
	int mid;
	if(start<end)
	{
		mid = (start + end) / 2;
		MergeSort(ar, start	, mid);
		MergeSort(ar, mid + 1, end );
		printf("\n");
		merge(ar,start ,mid , end);
	}
}

void merge(int* ar, int p, int q, int r)
{
	int ar1_size = (q - p) + 1 ;
	int ar2_size = (r - q ) ;
	int* ar1 = NULL ;
	int* ar2 = NULL;
	int j = p , i , k;

	ar1 = (int*)malloc(ar1_size * sizeof(int));
	if(ar1 == NULL)
    {
        fprintf(stderr, "out of memory\n"); 
        exit(EXIT_FAILURE); 
    }
     memset(ar1, 0, ar1_size * sizeof(int)); 


	ar2 = (int*)malloc(ar2_size * sizeof(int));
	if(ar2 == NULL)
    {
        fprintf(stderr, "out of memory\n"); 
        exit(EXIT_FAILURE); 
    }
    memset(ar2, 0, ar2_size * sizeof(int)); 

	printf("Error %d , %d\n",ar1_size ,ar2_size);


	for(i  = 0 ; i < ar1_size ; i++ ){
		ar1[i] = ar[p + j];
		j++;
	}

	for( i  = 0 ; i < ar2_size ; i++ ){
		ar2[i] = ar[q + 1 +j];
		j++;
	}
	
	i = 0  ;
	k = 0 ;
	j = 0 ;

	while(i < ar1_size && j < ar2_size)
	{
		if(ar1[i] <= ar2[j] )
		{
			ar[k] = ar1[i];
			i++;
			k++;
		}
		else{
			ar[k] = ar1[j];
			j++;
			k++;	
		}
	}

	while(i < ar1_size)
	{
		ar[k] = ar1[i];
		i++;
		k++;
	}

	while(j < ar2_size)
	{
		ar[k] = ar1[j];
		j++;
		k++;
	}

	free(ar1);
	ar1 = NULL;
	free(ar2);
	ar2 =NULL;
}

void show(int* ar, int n, char* msg)
{
	puts(msg);
	for(int i = 0 ; i < n ; i++ )
		printf("%d : [ %d ]\n", i, ar[i]);
}

/*
void MergeSort_1(int * ar1, int ar1_size, int* ar2, int ar2_size,int* ar)
{

	int mid;
	mid = (ar1_size + ar2_size) / 2;
	int start = 0; 
	if(start<end)
	{
		mid = (start + end) / 2;
		MergeSort(ar, start	, mid);
		MergeSort(ar, mid + 1, end );
		printf("\n");
		merge(ar,start ,mid , end);
	}
}


int merge_proc_1(int * ar1, int ar1_size, int* ar2, int ar2_size,int* ar)
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
*/