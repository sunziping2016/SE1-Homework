#include <stdio.h>

int main()
{
	unsigned long n;
	scanf("%lu", &n);
	printf("%lu\n", (n << 16) + (n >> 16));
	return 0;
}
