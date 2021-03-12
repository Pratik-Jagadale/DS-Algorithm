#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include"Quick_Sort.h"
int main(){

	FILE* fp; //File pointer
	char buff[50];   //maximum buffer size is 50
	int Arr[50];
	int i = 0,cnt = 0;

	fp = fopen("Temp.txt", "r+");     //current directory path of Temp.txt
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
	fp2 = fopen("Quick_Sort_OutPut.txt","w+");
	
	printf("\nSize of Array is = %d \n\nSorted Array : \n",cnt);
	fprintf(fp2,"\nSize of Array is = %d \n\nSorted Array : \n",cnt);
	for(i == 0; i <= cnt-1 ; i++){
	    printf("%d ",Arr[i]);	
	    fprintf(fp2," %d ", Arr[i]);
	}
	
	printf("\n ------------------------------------------------\n");	
	fprintf(fp2,"\n ------------------------------------------------\n");
	fclose(fp2);
	fclose(fp);
	return 0;
}

