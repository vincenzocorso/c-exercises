/*
	Esercizio 1
	Scrivere un algoritmo in C che calcola il numero di bit
	necessari per rappresentare un numero intero dato in input.
*/
#include <stdio.h>

int main()
{
	// Prende in input un numero intero positivo.
	unsigned int numero;
	printf("Inserisci un numero intero positivo: ");
	scanf("%u", &numero);
	
	// Calcola il numero di bit, shiftando a destra fino a quando il numero non diventa zero.
	unsigned int bit;
	for(bit = 0; numero; bit++)
		numero >>= 1;
	
	// Viene stampato il risultato.
	printf("Il numero di bit necessari per rappresentare %u è %u.\n", numero, bit);

	return 0;
}