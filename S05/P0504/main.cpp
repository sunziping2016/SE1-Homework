#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
	char word[81];
	int count[2][26] = {0}, i, j, len, yes = 1;
	for (i = 0; i < 2; ++i) {
		scanf("%s", word);
		len = strlen(word);
		for (j = 0; j < len; ++j)
			++count[i][toupper(word[j]) - 'A'];
	}
	for (i = 0; i < 26; ++i)
		if (count[0][i] != count[1][i]) {
			yes = 0;
			break;
		}
	if (yes)
		printf("yes\n");
	else
		printf("no\n");
	return 0;
}
