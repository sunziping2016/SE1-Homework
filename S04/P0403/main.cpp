#include <stdio.h>

int main()
{
	unsigned int n, product;
	scanf("%u", &n);
	while (n / 10) {
		product = 1;
		while (n != 0) {
			if (n % 10)
				product *= n % 10;
			n /= 10;
		}
		n = product;
	}
	printf("%u\n", n);
	return 0;
}
