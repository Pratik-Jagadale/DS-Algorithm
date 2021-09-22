/*...recursively summation values in subarray...*/

#include <stdio.h>

int sumArrEle(int* ar , int p , int q);

int main()
{
	int ar[10] = {0, 0, 3 , 4 , 5 , 6 , 7 , 0 , 0 , 0};

	int sum = sumArrEle(ar, 2 , 6);
	printf("summation of subarray from 2 to 6 is : %d\n",sum );
	return 0;
}

int sumArrEle(int* ar , int p , int q)
{
	if(p > q)
		return 1;

	return ( ar[p] + sumArrEle(ar, p + 1,q) );
}
