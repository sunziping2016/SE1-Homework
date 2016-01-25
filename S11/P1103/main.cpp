#include <stdio.h>
#include <malloc.h>

struct _Node {
	int coefficient;
	int exponential;
	struct _Node *next;
};
typedef struct _Node Node, *Polynomial;

Polynomial PolynomialInput(int n)
{
	int coef, exp;
	Node *head = NULL, *i = NULL;
	while (n != 0 && scanf("%d%d", &coef, &exp) == 2) {
		if (head == NULL)
			head = i = (Node *)malloc(sizeof(Node));
		else {
			i->next = (Node *)malloc(sizeof(Node));
			i = i->next;
		}
		i->coefficient = coef;
		i->exponential = exp;
		--n;
	}
	if (i) i->next = NULL;
	return head;
}

Polynomial PolynomialAdd(Polynomial poly1, Polynomial poly2)
{
	Node *head = NULL, *end = NULL;
	while (poly1 || poly2) {
		if (poly1 != NULL && poly2 != NULL && poly1->exponential == poly2->exponential && poly1->coefficient + poly2->coefficient == 0) {
			poly1 = poly1->next;
			poly2 = poly2->next;
			continue;
		}
		if (head == NULL)
			head = end = (Node *)malloc(sizeof(Node));
		else {
			end->next = (Node *)malloc(sizeof(Node));
			end = end->next;
		}
		if (poly2 == NULL || (poly1 != NULL && poly1->exponential < poly2->exponential)) {
			end->coefficient = poly1->coefficient;
			end->exponential = poly1->exponential;
			poly1 = poly1->next;
		}
		else if (poly1 != NULL && poly1->exponential == poly2->exponential) {
			end->coefficient = poly1->coefficient + poly2->coefficient;
			end->exponential = poly1->exponential;
			poly1 = poly1->next;
			poly2 = poly2->next;
		}
		else {
			end->coefficient = poly2->coefficient;
			end->exponential = poly2->exponential;
			poly2 = poly2->next;
		}
	}
	if(end) end->next = NULL;
	return head;
}

int PolynomialLen(Polynomial poly1)
{
	int i = 0;
	while (poly1) {
		++i;
		poly1 = poly1->next;
	}
	return i;
}

void PolynomialOutput(Polynomial head)
{
	while (head) {
		printf("%d %d\n", head->coefficient, head->exponential);
		head = head->next;
	}
}

void PolynomialDestroy(Polynomial head)
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
	Polynomial poly, poly1, poly2;
	scanf("%d", &n);
	poly1 = PolynomialInput(n);
	scanf("%d", &n);
	poly2 = PolynomialInput(n);
	poly = PolynomialAdd(poly1, poly2);
	printf("%d\n", PolynomialLen(poly));
	PolynomialOutput(poly);
	PolynomialDestroy(poly);
	PolynomialDestroy(poly1);
	PolynomialDestroy(poly2);
	return 0;
}
