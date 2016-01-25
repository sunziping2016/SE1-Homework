#include <stdio.h>
#define MAXN		6
int directions[8][2] = {
	{ -2, 1 },
	{ -1, 2 },
	{ 1, 2 },
	{ 2, 1 },
	{ 2, -1 },
	{ 1, -2 },
	{ -1, -2 },
	{ -2, -1 }
};
int n, count;

void dfs(int map[][MAXN], int i, int j, int s)
{
	int k;
	if (s == (n + 1) * (n + 1)) {
		++count;
		return;
	}
	map[i][j] = 1;
	for (k = 0; k < 8; ++k)
		if (i + directions[k][0] >= 0 && i + directions[k][0] <= n &&
			j + directions[k][1] >= 0 && j + directions[k][1] <= n && map[i + directions[k][0]][j + directions[k][1]] != 1)
			dfs(map, i + directions[k][0], j + directions[k][1], s + 1);
	map[i][j] = 0;
}
int main()
{
	int map[MAXN][MAXN];
	int i, j;
	scanf("%d%d%d", &n, &i, &j);
	dfs(map, i, j, 1);
	printf("%d\n", count);
	return 0;
}
