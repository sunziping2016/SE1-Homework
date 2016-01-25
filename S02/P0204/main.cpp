#include <stdio.h>

int main()
{
	int num;
	scanf("%d", &num);
	while (num != 0) {
		putchar(num % 10 + '0');
		num /= 10;
	}
	putchar('\n');
	return 0;
}
