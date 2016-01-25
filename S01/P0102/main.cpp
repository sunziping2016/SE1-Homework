#include <stdio.h>

int main()
{
	char ch;
	scanf("%c", &ch);
	printf("%c\n", ch - 'A' + 'a');
	return 0;
}
