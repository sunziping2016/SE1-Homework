<<<<<<< HEAD
#include <stdio.h>
#include <malloc.h>

struct _Node {
	int data;
	struct _Node *next;
};
typedef struct _Node Node;

Node *removeDuplicates(Node *head)
{
	Node *i, *j, *temp;
	if (head == NULL) return head;
	i = head;
	j = i->next;
	while (j) {
		if (i->data == j->data) {
			temp = j;
			j = j->next;
			free(temp);
		}
		else {
			i->next = j;
			i = i->next;
			j = j->next;
		}
	}
	i->next = NULL;
	return head;
}

Node *NodeInput(int n)
{
	int data;
	Node *head = NULL, *i = NULL;
	while (n != 0 && scanf("%d", &data) == 1) {
		if (head == NULL)
			head = i = (Node *)malloc(sizeof(Node));
		else {
			i->next = (Node *)malloc(sizeof(Node));
			i = i->next;
		}
		i->data = data;
		--n;
	}
	if(i) i->next = NULL;
	return head;
}

void NodeOutput(Node *head)
{
	if (head != NULL) {
		printf("%d", head->data);
		head = head->next;
	}
	while (head) {
		printf(" %d", head->data);
		head = head->next;
	}
	printf("\n");
}

void NodeDestroy(Node *head)
{
	Node *temp;
	while (head) {
		temp = head;
		head = head->next;
		free(temp);
	}
}

int main()
{
	int n;
	Node *head = NULL;
	scanf("%d", &n);
	head = NodeInput(n);
	removeDuplicates(head);
	NodeOutput(head);
	NodeDestroy(head);
	return 0;
}
=======
#include <stdio.h>
#include <malloc.h>

struct _Node {
	int data;
	struct _Node *next;
};
typedef struct _Node Node;

Node *removeDuplicates(Node *head)
{
	Node *i, *j, *temp;
	if (head == NULL) return head;
	i = head;
	j = i->next;
	while (j) {
		if (i->data == j->data) {
			temp = j;
			j = j->next;
			free(temp);
		}
		else {
			i->next = j;
			i = i->next;
			j = j->next;
		}
	}
	i->next = NULL;
	return head;
}

Node *NodeInput(int n)
{
	int data;
	Node *head = NULL, *i = NULL;
	while (n != 0 && scanf("%d", &data) == 1) {
		if (head == NULL)
			head = i = (Node *)malloc(sizeof(Node));
		else {
			i->next = (Node *)malloc(sizeof(Node));
			i = i->next;
		}
		i->data = data;
		--n;
	}
	if(i) i->next = NULL;
	return head;
}

void NodeOutput(Node *head)
{
	if (head != NULL) {
		printf("%d", head->data);
		head = head->next;
	}
	while (head) {
		printf(" %d", head->data);
		head = head->next;
	}
	printf("\n");
}

void NodeDestroy(Node *head)
{
	Node *temp;
	while (head) {
		temp = head;
		head = head->next;
		free(temp);
	}
}

int main()
{
	int n;
	Node *head = NULL;
	scanf("%d", &n);
	head = NodeInput(n);
	removeDuplicates(head);
	NodeOutput(head);
	NodeDestroy(head);
	return 0;
}
>>>>>>> afdb6a08941f398234b35730425286cb0c00c584
