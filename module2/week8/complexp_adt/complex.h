#ifndef COMPLEX_H
#define COMPLEX_H

typedef struct complex *complex;

complex cplx_init(double, double);
complex cplx_sum(complex, complex);
complex cplx_mul(complex, complex);
complex cplx_pow(complex, int);
double cplx_mod(complex); // module
double cplx_angle(complex);
double cplx_re(complex);
double cplx_im(complex);
void cplx_show(complex);
void cplx_print(complex);
void cplx_free(complex);

#endif
