<<<<<<< HEAD
#include <stdio.h>

int CalculateNum(int n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else if (n == 2)
		return 2;
	else if (n == 3)
		return 4;
	return CalculateNum(n - 1) + CalculateNum(n - 2) + CalculateNum(n - 3);
}

int main()
{
	int n;
	scanf("%d", &n);
	printf("%d\n", CalculateNum(n));
	return 0;
}
=======
#include <stdio.h>

int CalculateNum(int n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else if (n == 2)
		return 2;
	else if (n == 3)
		return 4;
	return CalculateNum(n - 1) + CalculateNum(n - 2) + CalculateNum(n - 3);
}

int main()
{
	int n;
	scanf("%d", &n);
	printf("%d\n", CalculateNum(n));
	return 0;
}
>>>>>>> afdb6a08941f398234b35730425286cb0c00c584
