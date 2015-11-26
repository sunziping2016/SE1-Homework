#include <stdio.h>

void strcompress(char *s)
{
	char buffer[1001];
	int i = 0, j = 0, nalpha[26] = {0}, index;
	while (s[j] != '\0')
		if (s[j] == ' ')
			buffer[i++] = s[j++];
		else {
			index = s[j] - 'a';
			++nalpha[index];
			if (nalpha[index] == 1 || nalpha[index] == 3 || nalpha[index] == 6)
				buffer[i++] = s[j++];
			else
				++j;
		}
	s[i] = '\0';
	while (i-- != 0)
		s[i] = buffer[i];
}

int main()
{
	char buffer[1001];
	gets(buffer);
	strcompress(buffer);
	puts(buffer);
	return 0;
}