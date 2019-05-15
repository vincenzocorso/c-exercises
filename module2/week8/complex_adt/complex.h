#ifndef COMPLEX_H
#define COMPLEX_H

typedef struct complex *complex;

complex cplx_init(double, double);
complex cplx_sum(complex, complex);
complex cplx_mul(complex, complex);
double cplx_mod(complex); // module
void cplx_print(complex);
void cplx_free(complex);

#endif
