#include <stdio.h>
#include <math.h>

int isPrime(int n)
{
	int i, end;
	if (n == 2) return 1;
	for (i = 2, end = (int)sqrt((double)n) + 1; i <= end; ++i)
		if (n%i == 0)
			return 0;
	return 1;
}

int main()
{
	int n, i, j=1, sum=0;
	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		while (!isPrime(++j));
		sum += j;
	}
	printf("%d\n", sum);
	return 0;
}
