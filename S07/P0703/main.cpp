#include <stdio.h>
#include <math.h>

int isPalindrome(int num)
{
	char s[20];
	int i, j = 0;
	while (num != 0) {
		s[j++] = num % 10;
		num /= 10;
	}
	for (i = 0, --j; i < j;  ++i, --j)
		if (s[i] != s[j])
			return 0;
	return 1;
}

int isPrime(int num)
{
	int i, end=(int)sqrt(num)+1;
	if (num < 2) return 0;
	for (i = 2; i < end; ++i)
		if (num%i == 0)
			return 0;
	return 1;
}

int main()
{
	int min, max, i, num = 0;
	scanf("%d%d", &min, &max);
	for (i = min; i <= max; ++i)
		if (isPalindrome(i) && isPrime(i))
			printf(num++ ? " %d" : "%d", i);
	printf("\n");
	return 0;
}