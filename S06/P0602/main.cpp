#include <stdio.h>

int main()
{
	char line1[100], line2[100];
	int len1 = 0, len2 = 0, split, ch, i, j;
	split = getchar();
	while ((ch = getchar()) != '\n' && ch != EOF) {
		if (ch > split)
			line1[len1++] = ch;
		else {
			for (i = 0; i < len2 && line2[i] < ch; ++i);
			for (j = len2; j >= i; --j)
				line2[j + 1] = line2[j];
			line2[i] = ch;
			++len2;
		}
	}
	line1[len1] = '\0';
	line2[len2] = '\0';
	printf("%s%c%s", line1, split, line2);
	return 0;
}