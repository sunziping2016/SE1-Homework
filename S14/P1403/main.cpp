#include <stdio.h>
#define MAXN		11
int num[MAXN][MAXN], n, nk;
int process[MAXN][MAXN];
int main()
{
	int i, j, k, max;
	scanf("%d%d", &n, &nk);
	for (i = 0; i < n; ++i)
		scanf("%1d", &num[i][i]);
	for (i = 0; i < n; ++i) {
		for (j = i + 1; j < n; ++j)
			num[i][j] = num[i][j - 1] * 10 + num[j][j];
		process[0][i] = num[0][i];
	}
	for (i = 1; i <= nk; ++i)
		for (j = 0; j < n; ++j) {
			max = 0;
			for (k = 1; k <= j; ++k)
				if (process[i - 1][k - 1] * num[k][j] > max)
					max = process[i - 1][k - 1] * num[k][j];
			process[i][j] = max;
		}
	printf("%d\n", process[nk][n - 1]);
	return 0;
}
