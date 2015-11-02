#include <stdio.h>

int main()
{
	int alpha[2][26] = { 0 }, i, ch;
	while ((ch = getchar()) != '\n' && ch != EOF) {
		if (ch >= 'a'&&ch <= 'z')
			++alpha[0][ch - 'a'];
		else if (ch >= 'A'&&ch <= 'Z')
			++alpha[1][ch - 'A'];
	}
	for (i = 0; i < 26; ++i)
		if (alpha[0][i] % 2) {
			printf("%c\n", i + 'a');
			return 0;
		}
	for (i = 0; i < 26; ++i)
		if (alpha[1][i] % 2) {
			printf("%c\n", i + 'A');
			return 0;
		}
	return 0;
}