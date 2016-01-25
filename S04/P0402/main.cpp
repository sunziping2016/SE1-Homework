#include <stdio.h>

int main()
{
	int a[16] = { 1, 3 }, i;
	for (i = 2; i < 16; ++i)
		a[i] = 4 * a[i - 1] - a[i - 2];
	scanf("%d", &i);
	printf("%d\n", a[i]);
	return 0;
}
