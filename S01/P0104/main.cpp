#include <stdio.h>

int hex2dec(char ch)
{
	return ch >= '0'&&ch <= '9' ? ch - '0' : ch - 'A' + 10;
}

int main()
{
	char a, b, c;
	int num;
	scanf("%c%c%c", &a, &b, &c);
	num = hex2dec(a) * 0x100 + hex2dec(b) * 0x10 + hex2dec(c);
	printf("0x%03X\n%04d\n%04o\n", num, num, num);
	return 0;
}
