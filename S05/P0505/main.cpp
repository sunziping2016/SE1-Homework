#include <stdio.h>
#include <math.h>

int main()
{
	int matrix[10][10], i, j, k, s, n, a, b, temp;
	double answers[10];
	int order[10];
	int row[10] = { 0 };
	scanf("%d", &n);
	for (i = 0; i < n; ++i)
		for (j = 0; j < n; ++j)
			scanf("%d", &matrix[i][j]);
	for (i = 0; i < n; ++i)
		scanf("%lf", &answers[i]);
	for (j = 0; j < n; ++j) {
		for (i = 0; row[i] || matrix[i][j] == 0; ++i)
			if (n == i+1) {
				printf("Error\n");
				return 0;
			}
		row[i] = 1;
		order[i] = j;
		for (k = 0; k < n; ++k)
			if (k != i && matrix[k][j] != 0) {
				a = abs(matrix[i][j]);
				b = abs(matrix[k][j]);
				while (b != 0) {
					temp = a%b;
					a = b;
					b = temp;
				}
				b = matrix[k][j] / a;
				a = matrix[i][j] / a;
				for (s = 0; s < n; ++s)
					matrix[k][s] = matrix[k][s] * a - matrix[i][s] * b;
				answers[k] = answers[k] * a - answers[i] * b;
			}
	}
	for (i = 0; i < n; ++i)
		printf("%.2f\n", answers[i] / matrix[i][order[i]]);
	return 0;
}
