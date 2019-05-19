#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "complex.h"

struct complex
{
	double module;
	double angle;
};

complex cplx_init(double module, double angle)
{
	complex a = malloc(sizeof(struct complex));
	if(a != NULL)
	{
		a->module = module;
		a->angle = angle;
	}
	
	return a;
}

complex cplx_sum(complex a, complex b)
{
	double re = a->module * cos(a->angle) + b->module * cos(b->angle);
	double im = a->module * sin(a->angle) + b->module * sin(b->angle);
	return cplx_init(sqrt(re*re+im*im), atan(im/re));
}

complex cplx_mul(complex a, complex b)
{
	return cplx_init(a->module * b->module, a->angle + b->angle);
}

complex cplx_pow(complex a, int exp)
{
	return cplx_init(pow(a->module, exp), exp * a->angle);
}

double cplx_mod(complex a)
{
	return a->module;
}

double cplx_angle(complex a)
{
	return a->angle;
}

double cplx_re(complex a)
{
	return a->module * cos(a->angle);
}

double cplx_im(complex a)
{
	return a->module * sin(a->angle);
}

void cplx_show(complex a)
{
	printf("%.3f(cos(%.3f)+i*sin(%.3f))", a->module, a->angle, a->angle);
}

void cplx_print(complex a)
{
	printf("%f+i*%f", a->module * cos(a->angle), a->module * sin(a->angle));
}

void cplx_free(complex a)
{
	free(a);
}
