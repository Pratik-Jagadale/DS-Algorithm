/*fid factorial  of number by res=cursively*/

unsigned long long fact(unsigned long long n);

int main()
{
	unsigned long long fac = fact(10);
	printf("%llu ",fac);
	return 0;
}

unsigned long long fact(unsigned long long n){

	if(n == 0)
		return 1;

	return (n * fact(n - 1));
}
