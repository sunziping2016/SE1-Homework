#include <stdio.h>

char *strncpy(char *s, char *t, int n)
{
	char *ret = s;
	while ((*s++ = *t++) && --n);
	return ret;
}

char* strncat(char * s, char *t, int n)
{
	char *ret = s;
	while (*s) ++s;
	while ((*s++ = *t++) && --n);
	return ret;
}

int main()
{
	char s[2002], t[1001], temp[1001];
	int n, len = 0;
	scanf("%s%s%d", s, t, &n);
	strncpy(temp, t, n);
	temp[n] = '\0';
	printf("%s\n", temp);
	while (s[len]) ++len;
	strncat(s, t, n);
	s[len + n] = '\0';
	printf("%s\n", s);
	return 0;
}
