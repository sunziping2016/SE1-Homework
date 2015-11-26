#include <stdio.h>

int expression(char *s)
{
	int num = 0, sign = 1;
	if (*s != '+' && *s != '-' && (*s < '0' || *s > '9'))
		return 0;
	if (*s == '+')
		++s;
	else if (s[0] == '-') {
		sign = -1;
		++s;
	}
	while (*s >= '0' && *s <= '9')
		num = num * 10 + *s++ - '0';
	return sign * num + expression(s);
}

int main()
{
	char exp[101];
	gets(exp);
	printf("%d\n", expression(exp));
	return 0;
}
