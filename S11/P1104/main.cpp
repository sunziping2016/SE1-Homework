#include <stdio.h>
#include <malloc.h>

struct _Node {
	int data;
	struct _Node *next;
};
typedef struct _Node Node;

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
	if (i) i->next = NULL;
	return head;
}

void NodeOutput(Node *head)
{
	while (head) {
		printf("%d\n", head->data);
		head = head->next;
	}
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

Node *NodeInsert(Node *head, int data)
{
	Node *node, *i, *j;
	node = (Node *)malloc(sizeof(Node));
	node->data = data;
	if (head == NULL || (head && data < head->data)) {
		node->next = head;
		head = node;
	}
	else {
		i = head;
		j = head->next;
		while (j && data > j->data) {
			i = j;
			j = j->next;
		}
		node->next = i->next;
		i->next = node;
	}
	return head;
}

Node *NodeRemove(Node *head, int data)
{
	Node *temp, *i, *j;
	if (head == NULL || head->data > data);
	else if (head->data == data) {
		temp = head;
		head = head->next;
		free(temp);
	}
	else {
		i = head;
		j = head->next;
		while (j && j->data < data) {
			i = j;
			j = j->next;
		}
		if (j && j->data == data) {
			i->next = j->next;
			free(j);
		}
	}
	return head;
}

int main()
{
	int n, i, data, oper;
	Node *head = NULL;
	scanf("%d", &n);
	head = NodeInput(n);
	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		scanf("%d %d", &data, &oper);
		if (oper)
			head = NodeInsert(head, data);
		else
			head = NodeRemove(head, data);
	}
	NodeOutput(head);
	NodeDestroy(head);
	return 0;
}
