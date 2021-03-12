#include<stdio.h>
#include<fcntl.h>
#include<string.h>

int CharArrtoint(char *);  //declaration of function of converting character array to integer value

void swap(int *low, int *high) {
  int t = *low;
  *low = *high;
  *high = t;
}

int partition(int Arr[], int low, int high) {

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

void quickSort(int array[], int low, int high) {
  if (low < high) {
    
    int pi = partition(array, low, high);
    
    quickSort(array, low, pi - 1);
    
    quickSort(array, pi + 1, high);
  }
}


int CharArrtoint(char *Arr){
	
	char c;
	int num=0,temp = 0,i = 0,incr = 1;
	while(Arr[i] != '\0'){
		c =Arr[i];

	switch (c)
	{ 
		case '0':
			temp = 0;
			break;
		case '1':
			temp = 1;
			break;
		case '2':
			temp = 2;
			break;
		case '3':
			temp = 3;
			break;
		case '4':
			temp = 4;
			break;
		case '5':
			temp = 5;
			break;
		case '6':
			temp = 6;		
			break;
		case '7':
			temp = 7;
			break;
		case '8':
			temp = 8;
			break;
		case '9':
			temp = 9;
			break;
		default:
			printf("Error\n");	
	}
	i++;
	num = (num * incr) + temp;	
	incr = incr * 10;
     }
	return num;
}

int main(){

	FILE* fp; //File pointer
	char buff[50];   //maximum buffer size is 50
	int Arr[50];
	int i = 0,cnt = 0;

	fp = fopen("input_file.txt", "r+");     //current directory path of Temp.txt
	if(fp==NULL){
	
		printf("therse is no such file\n====--------------=====\n");
		return -1;
	}
	
	fscanf(fp,"%s",buff);	
	printf("Numbers in your file :\n%s\n",buff);
		
	char * token = strtok(buff,",");  //c inbuilt function for seperate string 
	int temp;

	//loop for extract all characters
	while(token != NULL){	
		
	   temp = CharArrtoint(token); //convert char array to int value
	
	   //sscanf(token ,"%d",&temp);
	   Arr[cnt] = temp;
	   cnt++;
 	   token = strtok(NULL, ",");
	}
	
	quickSort(Arr,0,cnt-1);

	FILE* fp2;
	fp2 = fopen("OutPut.txt","w+");
	
	printf("\nSize of Array is = %d \nSorted Array : \n",cnt);
	for(i == 0; i <= cnt-1 ; i++){
	    printf("%d ",Arr[i]);	
	    fprintf(fp2," %d ", Arr[i]);
	}
		printf("\n");
	fclose(fp2);
	fclose(fp);
	return 0;
}

