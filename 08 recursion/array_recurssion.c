#include <stdio.h>

/*solve all of the below functions in recursively manner*/
int sumOfElementsInArray(int* ar, int n);
void show(int* ar, int n);
int sumOfPrimeNosInArray(int* ar, int n);

int N = 0;

int main(){

	//sumOfElementsInArray(ar, n - 1);
	//show(ar, 0);

	int ar[10] ={0 , 1 , 2 , 3 , 4 , 5 , 7 , 8 , 9};
	N = 10;
	int sum = sumOfPrimeNosInArray(ar, 0);
	printf("sum = %d\n", sum);
	return 0;
}

int sumOfElementsInArray(int* ar, int n)
{
	if(n == 0)
		return 0;

	return (ar[n] + sumOfElementsInArray(ar , n - 1));
}

void show(int* ar, int n)
{
	if(n < N){ // '==' is wrong because n = 0 should have to execute
		return ;
	}

	printf("[%d]\n",ar[n]);
	show(ar, n + 1);
}

/*recursively*/
int sumOfPrimeNosInArray( int* ar, int i)
{
	if(i == N - 1)
		return 0;

	int flag = 0;
	for(int j = 2 ; j < ar[i] / 2 ; j++)
		if(ar[i] % j != 0 ){
			flag = 1;
			break;
		}

		if(flag == 1){
			printf("Prim no %d\n",ar[i] );
			return( ar[i] + sumOfPrimeNosInArray(ar, i + 1) );
		}
	return sumOfPrimeNosInArray(ar, i + 1);
}
