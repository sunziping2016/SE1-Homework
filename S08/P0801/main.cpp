#include <stdio.h>

void merge(int *a, int *b, int m, int n, int *result)
{
	int i = 0, j = 0, k = 0;
	while (i != m || j != n) {
		if (j == n || i != m && a[i] < b[j])
			result[k++] = a[i++];
		else
			result[k++] = b[j++];
	}
}

int main()
{
	int a[10], b[10], result[20], m, n, i;
	scanf("%d", &m);
	for (i = 0; i < m; ++i)
		scanf("%d", &a[i]);
	scanf("%d", &n);
	for (i = 0; i < n; ++i)
		scanf("%d", &b[i]);
	merge(a, b, m, n, result);
	for (i = 0; i < m + n - 1; ++i)
		printf("%d ", result[i]);
	printf("%d\n", result[i]);
	return 0;
}
