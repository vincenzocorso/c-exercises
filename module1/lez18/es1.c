/*
	Dati due interi A e B a 32 bit scrivere la funzione f(A,B,i) detta
	crossover tra A e B di taglio i così definita:
	crossover(A, B, i) ->
		D = A(n-1) A(n-2) ... A(i+1) B(i) ... B(0)
		C = B(n-1) B(n-2) ... B(i+1) A(i) ... A(0)
	
	con:
		A = A(n-1) A(n-2) ... A(i+1) B(i) ... B(0)
		C = B(n-1) B(n-2) ... B(i+1) A(i) ... A(0)
*/
#include <stdio.h>

void crossover(int a, int b, int i, int* c, int* d);

int main()
{
	// Prende in input tre interi.
	int a, b, i;
	printf("Inserisci tre numeri interi: ");
	scanf("%d%d%d", &a, &b, &i);

	// Effettua il crossover richiamando la funzione.
	int c, d;
	crossover(a, b, i, &c, &d);

	// Stampa il risultato del crossover.
	printf("c=%d d=%d\n", c, d); 
	
	return 0;
}

void crossover(int a, int b, int i, int* c, int* d)
{
	*c = (b & (-1 << i)) | (a & ~(-1 << i));
	*d = (a & (-1 << i)) | (b & ~(-1 << i));
}
