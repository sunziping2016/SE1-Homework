#include <stdio.h>
#include <math.h>

int main()
{
	double a, b, c, delta;
	double x1, x2;
	scanf("%lf%lf%lf", &a, &b, &c);
	delta = b * b - 4 * a * c;
	if (fabs(delta) < 1e-8)
		printf("%.6f\n", -b / (2 * a));
	else if (delta > 0) {
		x1 = (-b + sqrt(delta)) / (2 * a);
		x2 = -b / a - x1;
		if(a > 0)
			printf("%.6f\n%.6f\n", x1, x2);
		else
			printf("%.6f\n%.6f\n", x2, x1);
	}
	else
		printf("Error\n");
	return 0;
}