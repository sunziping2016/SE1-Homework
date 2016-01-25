#include <stdio.h>

inline double tax(double income, double step)
{
	return income < step ? income*0.15 : step*0.15 + (income - step)*0.28;
}

int main()
{
	int type;
	double income, steps[] = {0.0, 17850.0, 23900.0, 29750.0, 14875.0};
	scanf("%d%lf", &type, &income);
	printf("%.6f\n", tax(income, steps[type]));
	return 0;
}
