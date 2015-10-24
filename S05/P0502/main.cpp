#include <stdio.h>

int main()
{
	int count = 1, max_count = 0, num, cur_num = 0, max_num = 0, i, n;
	scanf("%d%d", &n, &cur_num);
	for (i = 1; i < n; ++i) {
		scanf("%d", &num);
		if (num != cur_num) {
			if (count > max_count) {
				max_count = count;
				max_num = cur_num;
			}
			cur_num = num;
			count = 1;
		}
		else {
			++count;
		}
	}
	if (count > max_count)
		max_num = cur_num;
	printf("%d\n", max_num);
	return 0;
}
