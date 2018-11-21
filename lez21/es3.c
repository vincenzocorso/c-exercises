/*
	Scrivere una funzione in C che ritorna 1 se i valori di un
	vettore di N elementi float sono ordinati in modo crescente,
	0 altrimenti.
*/
#include <stdio.h>

unsigned char crescente(const unsigned int dimensione, const float vettore[]);

int main()
{
	float vettore1[5] = {5, 0, 8, 9, 6};
	float vettore2[5] = {1, 3, 5, 7, 9};
	float vettore3[5] = {1, 1, 2, 2, 3};
	float vettore4[5] = {1, 9, 18, 27, -5};

	printf("Il vettore1 è crescente? %u\n", crescente(5, vettore1));
	printf("Il vettore2 è crescente? %u\n", crescente(5, vettore2));
	printf("Il vettore3 è crescente? %u\n", crescente(5, vettore3));
	printf("Il vettore4 è crescente? %u\n", crescente(5, vettore4));

	return 0;
}

unsigned char crescente(const unsigned int dimensione, const float vettore[])
{
	unsigned int i;
	for(i = 1; i < dimensione && vettore[i - 1] <= vettore[i]; i++);

	return (i == dimensione);
}
