#include <stdio.h>
#include <malloc.h>

int findTwoSum(int *a, int n, int sum)
{
	int i, j;
	for (i = 0; i < n; ++i)
		for (j = i + 1; j < n; ++j)
			if (a[i] + a[j] == sum)
				return 1;
	return -1;
}

int main()
{
	int i, *a, n, sum;
	scanf("%d", &n);
	a = (int *)malloc(n * sizeof(int));
	for (i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	scanf("%d", &sum);
	printf("%d\n", findTwoSum(a, n, sum));
	free(a);
	return 0;
}
