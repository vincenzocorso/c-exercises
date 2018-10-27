/*
	Esercizio 2
	Dato un intero positivo minore di 100 stampare:
	A se il numero è >= 90
	B se il numero è >= 80 e < 90
	C se il numero è >= 70 e < 80
	D se il numero è >= 60 e < 70
	F per tutti gli altri casi.
*/
#include <stdio.h>

int main()
{
	// Prende in input un numero intero positivo.
	unsigned int numero;
	printf("Inserisci un intero positivo minore di 100: ");
	scanf("%u", &numero);
	
	// Alla prima condizione verificata, viene stampata la lettera.
	if(numero >= 90)
		puts("A");
	else if(numero >= 80)
		puts("B");
	else if(numero >= 70)
		puts("C");
	else if(numero >= 60)
		puts("D");
	else
		puts("F");
	
	return 0;
}