<<<<<<< HEAD
#include <stdio.h>

int main()
{
	char str[101];
	int i = 0, j, num, n = 0;
	scanf("%s%d", str, &num);
	while(1) {
		j = i;
		for (; str[i] != '\0' && str[i] != '*' && str[i] != '-'; ++i);
		if (++n == num) {
			printf("%d\n", i - j);
			break;
		}
		for (; str[i] != '\0' && (str[i] == '*' || str[i] == '-'); ++i);
	}
	return 0;
}
=======
#include <stdio.h>

int main()
{
	char str[101];
	int i = 0, j, num, n = 0;
	scanf("%s%d", str, &num);
	while(1) {
		j = i;
		for (; str[i] != '\0' && str[i] != '*' && str[i] != '-'; ++i);
		if (++n == num) {
			printf("%d\n", i - j);
			break;
		}
		for (; str[i] != '\0' && (str[i] == '*' || str[i] == '-'); ++i);
	}
	return 0;
}
>>>>>>> afdb6a08941f398234b35730425286cb0c00c584
