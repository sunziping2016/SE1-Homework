<<<<<<< HEAD
#include <stdio.h>
#include <malloc.h>

typedef struct _Node {
	int n;
	struct _Node *next;
} Node;

Node *NodeCreate(int n)
{
	int i;
	Node *head, *tail;
	head = tail = (Node *)malloc(sizeof(Node));
	tail->n = 1;
	for (i = 1; i < n; ++i) {
		tail->next = (Node *)malloc(sizeof(Node));
		tail = tail->next;
		tail->n = i + 1;
	}
	tail->next = head;
	return head;
}

Node *NodeRemove(Node *head, int m)
{
	Node *i, *j;
	if (m != 1) {
		i = j = head;
		while (--m) {
			i = j;
			j = j->next;
		}
		i->next = j->next;
		head = j->next;
		free(j);
	}
	else {
		j = head;
		while (j->next != head)
			j = j->next;
		j->next = head->next;
		free(head);
		head = j->next;
	}
	return head;
}

int main()
{
	int n, m;
	Node *head;
	scanf("%d%d", &n, &m);
	if (n < 1) return 0;
	head = NodeCreate(n);
	while (head->next != head)
		head = NodeRemove(head, m);
	printf("%d\n", head->n);
	free(head);
	return 0;
}
=======
#include <stdio.h>
#include <malloc.h>

typedef struct _Node {
	int n;
	struct _Node *next;
} Node;

Node *NodeCreate(int n)
{
	int i;
	Node *head, *tail;
	head = tail = (Node *)malloc(sizeof(Node));
	tail->n = 1;
	for (i = 1; i < n; ++i) {
		tail->next = (Node *)malloc(sizeof(Node));
		tail = tail->next;
		tail->n = i + 1;
	}
	tail->next = head;
	return head;
}

Node *NodeRemove(Node *head, int m)
{
	Node *i, *j;
	if (m != 1) {
		i = j = head;
		while (--m) {
			i = j;
			j = j->next;
		}
		i->next = j->next;
		head = j->next;
		free(j);
	}
	else {
		j = head;
		while (j->next != head)
			j = j->next;
		j->next = head->next;
		free(head);
		head = j->next;
	}
	return head;
}

int main()
{
	int n, m;
	Node *head;
	scanf("%d%d", &n, &m);
	if (n < 1) return 0;
	head = NodeCreate(n);
	while (head->next != head)
		head = NodeRemove(head, m);
	printf("%d\n", head->n);
	free(head);
	return 0;
}
>>>>>>> afdb6a08941f398234b35730425286cb0c00c584
