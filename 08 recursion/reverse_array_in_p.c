/*reverse the array in place by using recirsive approach*/
#include <stdio.h>

void reverse_array_in_p(int* ar , int start, int end);
void show(int* ar, int n, char* msg);

int main()
{
	int ar[10] = {0, 0, 3 , 4 , 5 , 6 , 7 , 0 , 0 , 0};

	reverse_array_in_p(ar, 2 , 6);
	show(ar, 10 , "After reverse:");

	return 0;
}

void reverse_array_in_p(int* ar , int start, int end)
{
	if(start >= end)
		return ;

	int tmp;
	tmp = ar[start];
	ar[start] = ar[end];
	ar[end] = tmp;
	reverse_array_in_p(ar, start + 1, end - 1);
	return ;
}

void show(int* ar, int n, char* msg)
{
	puts(msg);
	for(int i = 0 ; i < n ; i++)
		printf("%d:[%d]\n",i ,ar[i]);
}
