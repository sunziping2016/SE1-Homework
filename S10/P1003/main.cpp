#include <stdio.h>

typedef struct {
	char MC[101];
	double DJ;
	int SL;
} Order;

int main()
{
	Order orders[100];
	int nOrder, i;
	double sum = 0.0;
	scanf("%d", &nOrder);
	for (i = 0; i < nOrder; ++i)
		scanf("%s%lf%d", orders[i].MC, &orders[i].DJ, &orders[i].SL);
	for (i = 0; i < nOrder; ++i)
		sum += orders[i].SL * orders[i].DJ;
	printf("%.6lf\n", sum);
	return 0;
}
