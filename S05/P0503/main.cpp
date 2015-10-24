#include <stdio.h>
#include <string.h>

int main()
{
	char chars[101];
	int i, j, len, start = 0, wordsnum = 0, words = 0;
	int wordspos[51] = {0};
	gets(chars);
	len = strlen(chars);
	for (i = 0; i < len; ++i) {
		if (start == 0) {
			if (chars[i] == ' ')
				chars[i] = '\0';
			else {
				wordspos[wordsnum++] = i;
				start = 1;
			}
		}
		else {
			if (chars[i] == ' ') {
				chars[i] = '\0';
				start = 0;
			}
		}
	}
	for (i = 0; i < wordsnum; ++i)
		if (wordspos[i] != -1) {
			++words;
			for (j = i + 1; j < wordsnum; ++j)
				if (wordspos[j] != -1 && !strcmp(chars + wordspos[i], chars + wordspos[j]))
					wordspos[j] = -1;
		}
	printf("%d\n", words);
	return 0;
}
