#include <stdio.h>

int main()
{
	double num, sum = 0.0;
	int n = 0;
	FILE *file = fopen("D:\\S13\\P1301\\data1.in", "r");
	while (fscanf(file, "%lf", &num) == 1) {
		sum += num;
		++n;
	}
	fclose(file);
	printf("%.2lf\n", sum / n);
	return 0;
}
