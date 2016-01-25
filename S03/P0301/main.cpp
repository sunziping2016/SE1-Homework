#include <stdio.h>

int main()
{
	unsigned long min, max;
	scanf("%lu%lu", &min, &max);
	printf("%lu\n", (max*(max + 1)*(2 * max + 1) - min*(min - 1)*(2 * min - 1)) / 6);
	return 0;
}
