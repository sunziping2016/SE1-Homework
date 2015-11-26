#include <stdio.h>
#include <malloc.h>

int removeDuplicates(int *a, int n)
{
	int i = 1, j = 1;
	while (j != n) {
		if (a[j] != a[i - 1])
			a[i++] = a[j];
		++j;
	}
	return i;
}

int main()
{
	int i, n, *a;
	scanf("%d", &n);
	a = (int *)malloc(n * sizeof(int));
	for (i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	n = removeDuplicates(a, n);
	printf("%d\n", n);
	for (i = 0; i < n - 1; ++i)
		printf("%d ", a[i]);
	printf("%d\n", a[i]);
	free(a);
	return 0;
}
