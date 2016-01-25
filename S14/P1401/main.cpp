#include <stdio.h>
#define MAXN	512
int schedule[MAXN][MAXN];
int main()
{
	int n, i, j, k;
	scanf("%d", &n);
	for (i = 0; i < n; ++i)
		schedule[i][0] = i + 1;
	for (i = 1; i < n; i *= 2)
		for (j = 0; j < n; ++j)
			for (k = i; k < 2 * i; ++k)
				schedule[j][k] = schedule[j % (2 * i) < i ? j + i : j - i][k - i];
	for (i = 0; i < n; ++i) {
		printf("%d", schedule[i][1]);
		for (j = 2; j < n; ++j)
			printf(" %d", schedule[i][j]);
		printf("\n");
	}
	return 0;
}
