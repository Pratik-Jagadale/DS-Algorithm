/*
	Merge Sort...
*/

#include <stdio.h>

void mergeSort(int* Arr, int start, int end);
void merge(int* Arr,int start,int mid, int end);
void print(int* Arr,int cnt, char* msg);

int main(){
	int cnt,i;

	printf("Enter the count of elemnets :\n");
	scanf("%d",&cnt);

	int* Arr = (int* )malloc(cnt * sizeof(int));	
	if(Arr == NULL){
		printf("Dyanamic Memory Alloaction Failed \n");
	}

	printf("Insert the elements :\n");
	for(i = 0 ; i < cnt ; i++){
		scanf("%d",*Arr+Arr[i]);
	}

	print(Arr,cnt,"\nBefore sort :");
	mergeSort(Arr,0,cnt-1);
	print(Arr,cnt,"\nAfter Sort :");

	return 0;
}

void mergeSort(int* Arr, int start, int end){
	
	if(start < end){
		int mid = (start + (end - 1) / 2);
		mergeSort(Arr, start,mid);
		mergeSort(Arr, mid+1,end);
		merge(Arr, start, mid, end);
	}

	return 0;
}

void merge(int* Arr,int start,int mid, int end){
	int i = start, j = mid + 1 ,k = end;
	int* A = (int*)malloc(k*sizeof(int));

	while(i < mid && j < end){
		if(Arr[i] < Arr[j]){
			A[k] = Arr[i];
			i++;
		}
		else{
			A[k] = Arr[j];
			j++;
		}
		k++;
	}

	//if there is remaining elements in First part of array...
	while(i < mid){
		A[k] = Arr[i];
		i++;
		k++;
	}

	//if there is Remaining elemnets in second part of array...
	while(j < end){
		A[k] = Arr[j];
		j++;
		k++;
	}

	//copying data from temprarroy array to original Array...
	for(i = 0 ; i < end ; i++){
		Arr[i] = A[k];
	}

	return 0;
}

void print(int* Arr,int cnt, char* msg){
	puts(msg);

	for(int i = 0 ; i < cnt ; i++)
		printf("| %d |\n",Arr[i]);
	return 0;
}
