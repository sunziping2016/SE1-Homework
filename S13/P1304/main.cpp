#include <stdio.h>
#include <math.h>
#include <string.h>
#define MAXN		10

int isNotPrime[2 * MAXN * MAXN + 1];
int dfs(int *a, int n, int s, int *used)
{
	int i, j;
	if (s == n * n) {
		for (i = 0; i < n; ++i) {
			printf("%d", a[n * i]);
			for (j = 1; j < n; ++j)
				printf(" %d", a[n * i + j]);
			printf("\n");
		}
		return 1;
	}
	for (i = 0; i < n * n; ++i) {
		if (used[i] == 1) continue;
		if (s % n != 0 && isNotPrime[a[s - 1] + i + 1]) continue;
		if (s / n != 0 && isNotPrime[a[s - n] + i + 1]) continue;
		used[i] = 1;
		a[s] = i + 1;
		if (dfs(a, n, s + 1, used)) return 1;
		used[i] = 0;
	}
	return 0;
}
int main()
{
	int i = 2, j, n, endi, endj;
	int a[MAXN * MAXN], used[MAXN * MAXN];
	memset(used, 0, sizeof(used));
	scanf("%d", &n);
	endj = 2 * n * n;
	endi = int(sqrt(endj)) + 1;
	for (i = 2; i < endi; ++i) {
		if (isNotPrime[i] == 1) continue;
		for (j = i * i; j < endj; j += i)
			isNotPrime[j] = 1;
	}
	if (!dfs(a, n, 0, used))
		printf("0\n");
	return 0;
}
