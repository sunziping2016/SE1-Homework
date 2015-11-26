#include <stdio.h>
#include <string.h>

void multiply(char *s1, char *s2, char *result)
{
	int l1 = 0, l2 = 0, i, j, k, n1, n2, n, c, lr = 0;
	int res[20];
	l1 = strlen(s1);
	l2 = strlen(s2);
	for (i = 0; i < l1; ++i) {
		n1 = s1[l1 - i - 1] - '0';
		c = 0;
		for (j = 0; j < l2; ++j) {
			n2 = s2[l2 - j - 1] - '0';
			if (i + j < lr)
				n = n1 * n2 + c + res[i + j];
			else {
				n = n1 * n2 + c;
				lr = i + j + 1;
			}
			c = n / 10;
			res[i + j] = n % 10;
		}
		k = 0;
		while (c != 0) {
			if (i + j + k < lr)
				n = c + res[i + j + k];
			else {
				n = c;
				lr = i + j + k + 1;
			}
			c = n / 10;
			res[i + j + k] = n % 10;
		}
	}
	for (i = 0; i < lr; ++i)
		result[lr - i - 1] = res[i] + '0';
	result[lr] = '\0';
}


int main()
{
	char n1[10], n2[10], res[20];
	scanf("%s%s", n1, n2);
	multiply(n1, n2, res);
	printf("%s\n", res);
	return 0;
}
