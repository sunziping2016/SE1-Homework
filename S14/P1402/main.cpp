#include <stdio.h>
#define MAXN		32
#define MAXWEIGHT	20002
int weight[MAXN], n;
int package[MAXWEIGHT][MAXN];
int use[MAXWEIGHT][MAXN];

int getNum(int n)
{
	n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
	n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
	n = (n & 0x0f0f0f0f) + ((n >> 4) & 0x0f0f0f0f);
	n = (n & 0x00ff00ff) + ((n >> 8) & 0x00ff00ff);
	n = (n & 0x0000ffff) + ((n >> 16) & 0x0000ffff);
	return n;
}
int main()
{
	int i, j, maxweight;
	scanf("%d%d", &n, &maxweight);
	for (i = 1; i <= n; ++i)
		scanf("%d", &weight[i]);
	for (i = 1; i <= maxweight; ++i)
		for (j = 1; j <= n; ++j) {
			if (i - weight[j] >= 0 && package[i - weight[j]][j - 1] + weight[j] > package[i][j - 1]) {
				package[i][j] = package[i - weight[j]][j - 1] + weight[j];
				use[i][j] = use[i - weight[j]][j - 1] | (1 << j);
			}
			else {
				package[i][j] = package[i][j - 1];
				use[i][j] = use[i][j - 1];
				if (i - weight[j] >= 0 && package[i - weight[j]][j - 1] + weight[j] == package[i][j - 1] && getNum(use[i][j - 1]) > getNum(use[i - weight[j]][j - 1]) + 1)
					use[i][j] = use[i - weight[j]][j - 1] | (1 << j);
			}
		}
	printf("%d\n", getNum(use[maxweight][n]));
	for (i = 1; i <= n; ++i)
		if (use[maxweight][n] & (1 << i))
			printf("%d\n", weight[i]);
	return 0;
}
