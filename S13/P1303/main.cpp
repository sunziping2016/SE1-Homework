#include <stdio.h>

void myqsort(int *a, int n)
{
	int i, j, temp;
	if (n <= 1) return;
	for (i = 1, j = 1; j < n; ++j) {
		if (a[j] <= a[0]) {
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			++i;
		}
	}
	temp = a[i - 1];
	a[i - 1] = a[0];
	a[0] = temp;
	myqsort(a, i - 1);
	myqsort(a + i, j - i);
}

int main()
{
	int a[10000], i, n;
	scanf("%d", &n);
	for (i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	myqsort(a, n);
	if (n > 0) printf("%d", a[0]);
	for (i = 1; i < n; ++i)
		printf(" %d", a[i]);
	printf("\n");
	return 0;
}
