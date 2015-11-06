#include <stdio.h>
#include <math.h>

int unionSet(int a[], int na, int b[], int nb, int res[])
{
	int n = 0, i = 0, j = 0;
	while (i != na || j != nb) {
		if (j == nb || (i != na &&a[i] < b[j]))
			res[n++] = a[i++];
		else if (a[i] != b[j])
			res[n++] = b[j++];
		else {
			++j;
		}
	}
	return n;
}

int intersectionSet(int a[], int na, int b[], int nb, int res[])
{
	int n = 0, i = 0, j = 0;
	while (i != na && j != nb) {
		if (a[i] < b[j])
			++i;
		else if (a[i] > b[j])
			++j;
		else {
			res[n++] = a[i++];
			++j;
		}
	}
	return n;
}

int differenceSet(int a[], int na, int b[], int nb, int res[])
{
	int n = 0, i = 0, j = 0;
	while (i != na) {
		if (j == nb || a[i] < b[j])
			res[n++] = a[i++];
		else if (a[i] > b[j])
			++j;
		else {
			++i;
			++j;
		}
	}
	return n;
}

void printOperation(int a[], int na, int b[], int nb, int (*func)(int *, int, int *, int, int *))
{
	int res[2000], n, i;
	n = func(a, na, b, nb, res);
	for (i = 0; i < n - 1; ++i)
		printf("%d ", res[i]);
	if (n > 0)
		printf("%d\n", res[i]);
	else
		printf("\n");
}

int inputSet(int a[])
{
	int i, n;
	scanf("%d", &n);
	for (i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	return n;
}

int main()
{
	int na, a[1000], nb, b[1000];
	na = inputSet(a);
	nb = inputSet(b);
	printOperation(a, na, b, nb, intersectionSet);
	printOperation(a, na, b, nb, unionSet);
	printOperation(a, na, b, nb, differenceSet);
	return 0;
}