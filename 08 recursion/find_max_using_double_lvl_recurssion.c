#include <stdio.h>

int findMax(int* ar, int start, int end);

int main()
{

	int ar[10] = {0, 0, 3 , 4 , 5 , 6 , 7 , 0 , 0 , 0};

	int max = findMax(ar, 2 , 6);
	printf("%d\n", max);
	return 0;
}

int findMax(int* ar, int start, int end)
{
	if(start == end)
		return pa[start];
	int max_left ;
	int max_right;
	int mid = (start + end) / 2;

	max_left = findMax(ar, start , mid);
	max_right = findMax(ar, mid + 1 , end);

	if(max_left > max_right)
		return max_left;
	return max_right;
}
