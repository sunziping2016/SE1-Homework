#include <stdio.h>

int main()
{
	double numbers[41] = { 1, 2 }, sum=0.0;
	int i, n;
	for (i = 2;i < 41;++i)
		numbers[i] = numbers[i - 1] + numbers[i - 2];
	scanf("%d", &n);
	for (i = 0; i < n; ++i)
		sum += numbers[i + 1] / numbers[i];
	printf("%.2f\n", sum);
	return 0;
}