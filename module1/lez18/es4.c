/*
	Utilizzare una funzione per implementare lo scambio tra due
	variabili intere A e B senza utilizzare una variabile di comodo.
*/
#include <stdio.h>

#define XOR(A,B) (A & ~B) | (B & ~A)

void swap(int* a, int* b);

int main()
{
	// Prende in input due numeri interi.
	int a, b;
	printf("Inserisci due numeri interi: ");
	scanf("%d%d", &a, &b);

	// Richiama la funzione swap che scambia il contenuto dei due numeri.
	printf("Prima -> a=%d b=%d\n", a, b); 
	swap(&a, &b);
	printf("Dopo -> a=%d b=%d\n", a, b); 

	return 0;
}

void swap(int* a, int* b)
{
	*a = XOR(*a, *b);
	*b = XOR(*a, *b);
	*a = XOR(*a, *b);
}
