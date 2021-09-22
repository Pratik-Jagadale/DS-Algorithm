/*...recursively multypily values in subarray...*/

#include <stdio.h>

int MultyplyArrEle(int* ar , int p , int q);

int main()
{
	int ar[10] = {0, 0, 3 , 4 , 5 , 6 , 7 , 0 , 0 , 0};

	int mul = MultyplyArrEle(ar, 2 , 6);
	printf("multiplication of subarray fron 2 to 6 is : %d\n",mul );
	return 0;
}

int MultyplyArrEle(int* ar , int p , int q)
{
	if(p > q)
		return 1;

	return ( ar[p] * MultyplyArrEle(ar, p + 1,q) );
}
