<<<<<<< HEAD
#include <stdio.h>

int main()
{
	int ch1, ch2, n = 1;
	FILE *file1 = fopen("D:\\S13\\P1302\\file1.txt", "r");
	FILE *file2 = fopen("D:\\S13\\P1302\\file2.txt", "r");;
	while(1) {
		ch1 = fgetc(file1);
		ch2 = fgetc(file2);
		if (ch1 == EOF && ch2 == EOF) {
			printf("same\n");
			break;
		}
		if (ch1 != ch2) {
			printf("%d\n", n);
			break;
		}
		if (ch1 == '\n')
			++n;
	}
	fclose(file1);
	fclose(file2);
	return 0;
}
=======
#include <stdio.h>

int main()
{
	int ch1, ch2, n = 1;
	FILE *file1 = fopen("D:\\S13\\P1302\\file1.txt", "r");
	FILE *file2 = fopen("D:\\S13\\P1302\\file2.txt", "r");;
	while(1) {
		ch1 = fgetc(file1);
		ch2 = fgetc(file2);
		if (ch1 == EOF && ch2 == EOF) {
			printf("same\n");
			break;
		}
		if (ch1 != ch2) {
			printf("%d\n", n);
			break;
		}
		if (ch1 == '\n')
			++n;
	}
	fclose(file1);
	fclose(file2);
	return 0;
}
>>>>>>> afdb6a08941f398234b35730425286cb0c00c584
