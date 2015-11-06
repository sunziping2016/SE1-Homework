#include <stdio.h>
#include <string.h>

void RegularPlural(char str[])
{
	int len = strlen(str);
	if (len > 0 && (str[len - 1] == 's' || str[len - 1] == 'x' || str[len - 1] == 'z') ||
		len > 1 && str[len - 1] == 'h' && (str[len - 2] == 'c' || str[len - 2] == 's')) {
		str[len++] = 'e';
		str[len++] = 's';
		str[len] = '\0';
	}
	else if (len > 1 && str[len - 1] == 'y' && str[len - 2] != 'a'&& str[len - 2] != 'e'&&
		str[len - 2] != 'i'&& str[len - 2] != 'o'&& str[len - 2] != 'u') {
		str[len - 1] = 'i';
		str[len++] = 'e';
		str[len++] = 's';
		str[len] = '\0';
	}
	else {
		str[len++] = 's';
		str[len] = '\0';
	}
}

int main()
{
	char word[25];
	scanf("%s", word);
	RegularPlural(word);
	printf("%s\n", word);
	return 0;
}