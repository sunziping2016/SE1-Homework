#include <stdio.h>
#include <math.h>

int main()
{
	double a, b, c, p, area, max;
	scanf("%lf%lf%lf", &a, &b, &c);
	max = a;
	if (max < b) max = b;
	if (max < c) max = c;
	if (fabs(a - b) < c&&a + b > c) {
		p = (a + b + c) / 2.0;
		area = sqrt(p*(p - a)*(p - b)*(p - c));
		printf("%.6f\n", 2.0*area / max);
	}
	else
		printf("NO\n");
	return 0;
}
