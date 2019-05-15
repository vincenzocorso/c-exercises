#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "complex.h"

struct complex
{
	double re;
	double im;
};

complex cplx_init(double re, double im)
{
	complex a = malloc(sizeof(struct complex));
	if(a != NULL)
	{
		a->re = re;
		a->im = im;
	}
	
	return a;
}

complex cplx_sum(complex a, complex b)
{
	return cplx_init(a->re + b->re, a->im + b->im);
}

complex cplx_mul(complex a, complex b)
{
	return cplx_init(a->re * b->re - a->im * b->im, a->re * b->im + a->im * b->re);
}

double cplx_mod(complex a)
{
	return sqrt(a->re * a->re + a->im * a->im);
}

void cplx_print(complex a)
{
	printf("%.2f+i%.2f", a->re, a->im);
}

void cplx_free(complex a)
{
	free(a);
}
