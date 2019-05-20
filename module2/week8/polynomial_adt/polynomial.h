#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

typedef struct polynomial *polynomial;

polynomial plm_init(int, double *);
polynomial plm_sum(polynomial, polynomial);
polynomial plm_mul(polynomial, polynomial);
double plm_eval(polynomial, double);
void plm_print(polynomial);
void plm_free(polynomial);

#endif
