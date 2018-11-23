/*
	Scrivere una funzione in C che accetta come parametro di
	input un vettore e ritorna 1 se gli elementi di tale vettore
	sono tutti uguali, zero altrimenti.
*/
#include <stdio.h>

int entrate_uguali(const unsigned int dimensione, const int vettore[dimensione]);

int main()
{
	int vettore1[5] = {1, 1, 1, 1, 1};
	int vettore2[5] = {0, 1, 2, 3, 4};
	int vettore3[5] = {1, 1, 1, 1, 0};

	printf("%d\n", entrate_uguali(5, vettore1));
	printf("%d\n", entrate_uguali(5, vettore2));
	printf("%d\n", entrate_uguali(5, vettore3));

	return 0;
}

int entrate_uguali(const unsigned int dimensione, const int vettore[dimensione])
{
	int entrata = vettore[0];

	unsigned int i;
	for(i = 2; i < dimensione && vettore[i] == entrata; i++);

	return (i == dimensione);
}
