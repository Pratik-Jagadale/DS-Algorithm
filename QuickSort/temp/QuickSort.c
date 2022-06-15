#include<stdio.h>
#include<fcntl.h>
#include<string.h>

int Char_to_int(char *);
void swap(int* low, int* high);
int Partition(int*, int low, int high);
void QuickSort(int *, int low, int high);

int main() {

	FILE* filepointer;
	char Temp_Array[50];
	int iArr[50];
	int i = 0, count = 0;

	filepointer = fopen("input_file.txt", "r+");
	if (filepointer == NULL) {

		printf("therse is no such file\n====--------------=====\n");
		return -1;
	}

	fscanf(filepointer, "%s", Temp_Array);
	printf("Numbers in your file :\n%s\n", Temp_Array);

	char* token = strtok(Temp_Array, ",");
	int temp;

	while (token != NULL) {

		temp = Char_to_int(token);

		;
		iArr[count] = temp;
		count++;
		token = strtok(NULL, ",");
	}

	QuickSort(iArr, 0, count - 1);

	FILE* fp2;
	fp2 = fopen("OutPut.txt", "w+");

	printf("\nSize of Array is = %d \nSorted Array : \n", count);
	for (i == 0; i <= count - 1; i++) {
		printf("%d ", iArr[i]);
		fprintf(fp2, " %d ", iArr[i]);
	}
	printf("\n");
	fclose(fp2);
	fclose(filepointer);
	return 0;
}


void swap(int *low, int *high) {
  int t = *low;
  *low = *high;
  *high = t;
}

int Partition(int* Arr, int low, int high) {

	int i = low;
	int j = high;
	int pivot = Arr[low];
	
	while(i < j)
	{
		while(Arr[i] <= pivot)
		{
			i++;
		}
		while(Arr[j] > pivot)
		{
			j--;
		}
	
		if(i < j)
		{
			swap(&Arr[i],&Arr[j]);
		}
	}
	Arr[low] = Arr[j];
	Arr[j] = pivot;
	return j;
}

void QuickSort(int* Array, int low, int high) {
  if (low < high) {
    
    int pivot = Partition(Array, low, high);
    
    QuickSort(Array, low, pivot - 1);
    
    QuickSort(Array, pivot + 1, high);
  }
}


int Char_to_int(char *Arr){
	
	char c;
	int num=0,t = 0,i = 0,incremnent = 1;
	while(Arr[i] != '\0'){
		c =Arr[i];

	switch (c)
	{ 
		case '0':
			t = 0;
			break;
		case '1':
			t = 1;
			break;
		case '2':
			t = 2;
			break;
		case '3':
			t = 3;
			break;
		case '4':
			t = 4;
			break;
		case '5':
			t = 5;
			break;
		case '6':
			t = 6;		
			break;
		case '7':
			t = 7;
			break;
		case '8':
			t = 8;
			break;
		case '9':
			t = 9;
			break;
		default:
			printf("Error\n");	
	}
	i++;
	num = (num * incremnent) + t;	
	incremnent = incremnent * 10;
     }
	return num;
}

