<<<<<<< HEAD
#include <stdio.h>

typedef struct {
	double real, img;
} Complex;

Complex *Add(Complex *a, Complex *b, Complex *r)
{
	r->real = a->real + b->real;
	r->img = a->img + b->img;
	return r;
}
Complex *Minus(Complex *a, Complex *b, Complex *r)
{
	r->real = a->real - b->real;
	r->img = a->img - b->img;
	return r;
}
Complex *Multiply(Complex *a, Complex *b, Complex *r)
{
	r->real = a->real * b->real - a->img * b->img;
	r->img = a->real * b->img + a->img * b->real;
	return r;
}
Complex *Divide(Complex *a, Complex *b, Complex *r)
{
	double d;
	d = b->real * b->real + b->img * b->img;
	r->real = (a->real * b->real + a->img * b->img) / d;
	r->img = (a->img * b->real - a->real * b->img) / d;
	return r;
}

int main()
{
	Complex a, b, r;
	char ch;
	scanf("%c%lf%lf%lf%lf", &ch, &a.real, &a.img, &b.real, &b.img);
	switch (ch)
	{
	case '+':
		Add(&a, &b, &r);
		break;
	case '-':
		Minus(&a, &b, &r);
		break;
	case '*':
		Multiply(&a, &b, &r);
		break;
	case '/':
		Divide(&a, &b, &r);
		break;
	}
	printf("%.2f+%.2fi\n", r.real, r.img);
	return 0;
}
=======
#include <stdio.h>

typedef struct {
	double real, img;
} Complex;

Complex *Add(Complex *a, Complex *b, Complex *r)
{
	r->real = a->real + b->real;
	r->img = a->img + b->img;
	return r;
}
Complex *Minus(Complex *a, Complex *b, Complex *r)
{
	r->real = a->real - b->real;
	r->img = a->img - b->img;
	return r;
}
Complex *Multiply(Complex *a, Complex *b, Complex *r)
{
	r->real = a->real * b->real - a->img * b->img;
	r->img = a->real * b->img + a->img * b->real;
	return r;
}
Complex *Divide(Complex *a, Complex *b, Complex *r)
{
	double d;
	d = b->real * b->real + b->img * b->img;
	r->real = (a->real * b->real + a->img * b->img) / d;
	r->img = (a->img * b->real - a->real * b->img) / d;
	return r;
}

int main()
{
	Complex a, b, r;
	char ch;
	scanf("%c%lf%lf%lf%lf", &ch, &a.real, &a.img, &b.real, &b.img);
	switch (ch)
	{
	case '+':
		Add(&a, &b, &r);
		break;
	case '-':
		Minus(&a, &b, &r);
		break;
	case '*':
		Multiply(&a, &b, &r);
		break;
	case '/':
		Divide(&a, &b, &r);
		break;
	}
	printf("%.2f+%.2fi\n", r.real, r.img);
	return 0;
}
>>>>>>> afdb6a08941f398234b35730425286cb0c00c584
