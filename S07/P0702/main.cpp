#include <stdio.h>

int my_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2) {
		++s1;
		++s2;
	}
	return *s1 - *s2;
}

int main()
{
	char s1[101], s2[101];
	gets(s1);
	gets(s2);
	printf("%d", my_strcmp(s1, s2));
	return 0;
}