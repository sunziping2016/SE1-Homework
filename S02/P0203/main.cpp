#include <stdio.h>

int main()
{
	int nSpace = 0, nNewline = 0, nOthers = 0, ch;
	while ((ch = getchar()) != '#')
		switch (ch) {
			case ' ' : ++nSpace;   break;
			case '\n': ++nNewline; break;
			default  : ++nOthers;  break;
		}
	printf("%d %d %d\n", nSpace, nNewline, nOthers);
	return 0;
}
