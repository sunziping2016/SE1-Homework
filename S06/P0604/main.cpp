#include <stdio.h>

int main()
{
	int digits[10], n = 0, ch, exist[9] = { 0 }, i, visit[10] = { 0 }, pos = 0;
	while ((ch = getchar()) != '\n' && ch != EOF) {
		if (ch == '0') {
			printf("no\n");
			return 0;
		}
		digits[n++] = ch - '0';
		++exist[ch - '1'];
	}
	for (i = 0; i < 9; ++i)
		if (exist[i]>1) {
			printf("no\n");
			return 0;
		}
	do {
		pos = (pos + digits[pos]) % n;
		if (visit[pos] == 1) {
			printf("no\n");
			return 0;
		}
		visit[pos] = 1;
	} while (pos != 0);
	for (i = 0; i < n; ++i)
		if (visit[i] == 0) {
			printf("no\n");
			return 0;
		}
	printf("yes\n");
	return 0;
}