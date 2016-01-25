#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct _Student {
	long id;
	char name[21];
	char gender[10];
	int grade;
	int rank;
	struct _Student * next;
} Student;

Student *StudentInsert(Student *head, Student *temp)
{
	Student *node, *i, *j;
	node = (Student *)malloc(sizeof(Student));
	*node = *temp;
	if (head == NULL || (head && (temp->grade > head->grade || (temp->grade == head->grade && temp->id < head->id)))) {
		node->next = head;
		head = node;
	}
	else {
		i = head;
		j = head->next;
		while (j && (temp->grade < j->grade || (temp->grade == j->grade && temp->id > j->id))) {
			i = j;
			j = j->next;
		}
		node->next = i->next;
		i->next = node;
	}
	return head;
}

Student *StudentInput(int n)
{
	Student *head = NULL, *i = NULL, temp;
	while (n != 0 && scanf("%ld%s%s%d", &temp.id, temp.name, temp.gender, &temp.grade) == 4) {
		head = StudentInsert(head, &temp);
		--n;
	}
	if (i) i->next = NULL;
	return head;
}

void StudentOutput(Student *head)
{
	while (head) {
		printf("%ld %s %s %d\n", head->id, head->name, head->gender, head->grade);
		head = head->next;
	}
}

void StudentRank(Student *head)
{
	int n = 1, grade = 0, i = 1;
	if (head == NULL) return;
	grade = head->grade;
	while (head) {
		if (grade != head->grade) {
			grade = head->grade;
			n = i;
		}
		head->rank = n;
		head = head->next;
		++i;
	}
}

void StudentDestroy(Student *head)
{
	Student *temp;
	while (head) {
		temp = head;
		head = head->next;
		free(temp);
	}
}

Student *StudentRemove(Student *head, int n)
{
	Student *temp, *i, *j;
	if (head == NULL || n < 0)
		return head;
	else if (n == 1) {
		while (head && head->rank == n) {
			temp = head;
			head = head->next;
			free(temp);
		}
	}
	else {
		i = head;
		j = head->next;
		while (j && j->rank < n) {
			i = j;
			j = j->next;
		}
		while(j && j->rank == n) {
			temp = j;
			j = j->next;
			free(temp);
		}
		i->next = j;
	}
	return head;
}

int main()
{
	int n, i, k;
	Student *head;
	scanf("%d", &n);
	head = StudentInput(n);
	StudentRank(head);
	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		scanf("%*s%d", &k);
		head = StudentRemove(head, k);
	}
	StudentOutput(head);
	StudentDestroy(head);
	return 0;
}
