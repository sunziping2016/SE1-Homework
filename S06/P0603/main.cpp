#include <stdio.h>

int main()
{
	int oldnumber = 0, number, digits[4], i, j, k, num, max, min;
	scanf("%d", &number);
	while (oldnumber != number) {
		oldnumber = number;
		for (i = 0; i < 4; ++i) {
			digits[i] = number % 10;
			number /= 10;
		}
		for (i = 1; i < 4; ++i) {
			num = digits[i];
			for (j = 0; j < i && digits[j] < num; ++j);
			for (k = i; k > j; --k)
				digits[k] = digits[k - 1];
			digits[j] = num;
		}
		min = max = 0;
		for (i = 0; i < 4; ++i) {
			min = min * 10 + digits[i];
			max = max * 10 + digits[3 - i];
		}
		number = max - min;
	}
	printf("%d\n", number);
	return 0;
}
