#include <stdio.h>

int print_array_reverse(int* ar, int n );

int main()
{
	int ar[10] = { 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10};
	print_array_reverse(ar, 10);
}

int print_array_reverse(int* ar, int n ){

	if(n < 0 )
		return 0;

	printf("%d : [%d]\n", n, ar[n]);
	print_array_reverse(ar, n - 1);
	return 0;
}
