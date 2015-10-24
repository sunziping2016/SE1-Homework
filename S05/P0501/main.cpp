#include <stdio.h>

int main()
{
	char str[21], ch;
	int i;
	scanf("%s%*c%c", str, &ch);
	for (i = 0; str[i]; ++i)
		if (ch != str[i])
			putchar(str[i]);
	putchar('\n');
	return 0;
}
