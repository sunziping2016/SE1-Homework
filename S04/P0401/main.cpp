#include <stdlib.h>
#include <stdio.h>

#define NUMBER 5

int main()
{
	int a[NUMBER], num, i = 0, j, flag, temp, min, max;
	unsigned int seed;
	scanf("%u%d%d", &seed, &min, &max);
	srand(seed);
	while (i != NUMBER) {
		num = rand();
		flag = 0;
		if (num<min || num>max)
			flag = 1;
		for (j = 0; j < i; ++j)
			if (a[j] == num)
				flag = 1;
		if (!flag)
			a[i++] = num;
	}
	// bubble sort
	for (i = 0; i != NUMBER - 1; ++i) {
		for (j = NUMBER - 1; j > i; --j) {
			if (a[j - 1] > a[j]) {
				temp = a[j-1];
				a[j - 1] = a[j];
				a[j] = temp;
			}
		}
	}
	for (i = 0; i < NUMBER -1; ++i)
		printf("%d ", a[i]);
	printf("%d\n", a[NUMBER - 1]);
	return 0;
}
