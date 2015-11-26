#include <stdio.h>

int main()
{
	char word[2][1001], *index[2][500] = { { word[0] }, { word[1] } };
	int nWords[2] = { 1, 1 }, i, j, k;
	int alpha[2][500][26] = { 0 }, first = 1;
	int found[500] = { 0 };
	for (i = 0; i < 2; ++i) {
		gets(word[i]);
		for (j = 0; word[i][j]; ++j)
			if (word[i][j] == ' ') {
				index[i][nWords[i]++] = word[i] + j + 1;
				word[i][j] = '\0';
			}
		for (j = 0; j < nWords[i]; ++j)
			for (k = 0; index[i][j][k]; ++k)
				++alpha[i][j][index[i][j][k] - 'a'];
	}
	for (j = 0; j < nWords[1]; ++j)
		for (i = 0; i < nWords[0]; ++i) {
			if (found[i]) continue;
			for (k = 0; k < 26 && alpha[0][i][k] == alpha[1][j][k]; ++k);
			if (k == 26) {
				if (first) {
					printf("%s", index[0][i]);
					first = 0;
				}
				else
					printf(" %s", index[0][i]);
				found[i] = 1;
				break;
			}
		}
	printf("\n");
	return 0;
}
