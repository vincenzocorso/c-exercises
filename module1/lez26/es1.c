/*
	Scrivere una funzione che dati due vettori di reali
	v e w calcoli il prodotto scalare tra i due.
*/
#include <stdio.h>

#define SIZE	5

float prodotto_scalare(int dimensione, float v[], float w[]);

int main()
{
	float v[SIZE] = {4.0, 5.7, 6.0, 7.0, 2.3};
	float w[SIZE] = {3.3, 2.9, 4.1, 8.2, 2.6};

	printf("Il prodotto scalare è %f\n", prodotto_scalare(SIZE, v, w));
	
	return 0;
}

float prodotto_scalare(int dimensione, float v[], float w[])
{
	float risultato = 0.0;
	
	for(size_t i = 0; i < dimensione; i++)
		risultato += v[i] * w[i];

	return risultato;
}
