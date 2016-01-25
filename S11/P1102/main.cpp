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

Node *intersect(Node *head1, Node *head2)
{
	Node *head = NULL, *end = NULL;
	while (head1 || head2) {
		if (head2 == NULL || (head1 != NULL && head1->data < head2->data))
			head1 = head1->next;
		else if (head1 != NULL && head1->data == head2->data) {
			if (head == NULL)
				head = end = (Node *)malloc(sizeof(Node));
			else {
				end->next = (Node *)malloc(sizeof(Node));
				end = end->next;
			}
			end->data = head1->data;
			head1 = head1->next;
			head2 = head2->next;
		}
		else
			head2 = head2->next;
	}
	if(end) end->next = NULL;
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
	Node *head, *head1, *head2;
	scanf("%d", &n);
	head1 = NodeInput(n);
	scanf("%d", &n);
	head2 = NodeInput(n);
	head = intersect(head1, head2);
	NodeOutput(head);
	NodeDestroy(head);
	NodeDestroy(head1);
	NodeDestroy(head2);
	return 0;
}
