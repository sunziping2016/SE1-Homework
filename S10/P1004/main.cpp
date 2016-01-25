#include <stdio.h>
#include <string.h>

typedef struct {
	char name[21];
	int gender; // 0: male, 1: female
	int age, grade;
} Student;

int main()
{
	Student students[1001], *index[1001], *temp;
	int nStudent, i, j;
	char buffer[21];
	scanf("%d", &nStudent);
	for (i = 0; i < nStudent; ++i) {
		scanf("%s%s%d%d", students[i].name, buffer, &students[i].age, &students[i].grade);
		students[i].gender = strcmp(buffer, "male") ? 1 : 0;
		index[i] = &students[i];
	}
	for (i = 0; i < nStudent - 1; ++i)
		for (j = nStudent - 1; j > i; --j)
			if (index[j - 1]->grade > index[j]->grade) {
				temp = index[j - 1];
				index[j - 1] = index[j];
				index[j] = temp;
			}
	for (i = 0; i < nStudent; ++i)
		printf("%s %s %d %d\n", index[i]->name, (index[i]->gender ? "female" : "male"), index[i]->age, index[i]->grade);
	return 0;
}
