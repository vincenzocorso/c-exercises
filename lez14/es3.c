/*
	Esercizio 3
	Dati un intero positivi k, scrivere un programma che calcola:
	sommatoria per i=1 a k della sommatoria per j=1 a i di [1/(i+j)]^2
*/
#include <stdio.h>

// Definisce lo XOR come funzione macro.
#define XOR(a, b) (a & ~b) | (b & ~a)

int main()
{
	// Prende in input un numero intero positivo.
	unsigned int k;
	printf("Inserisci un numero intero positivo: ");
	scanf("%u", &k);
	
	/* Calcola la sommatoria del quadrato della sommatoria.
	   Il quadrato viene eseguito quando tutto il termine della
	   sommatoria interna viene calcolato. */
	double somma = 0.0, termine = 0.0;
	for(unsigned int i = 1; i <= k; i++)
	{
		for(unsigned int j = 1; j <= i; j++)
			termine += 1.0 / (i + j);
		
		somma += termine * termine;
		termine = 0.0;
	}
	
	// Viene stampato il risultato.
	printf("Il risultato è %f.\n", somma);

	return 0;
}