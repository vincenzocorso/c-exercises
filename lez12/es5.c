/*
	Esercizio 5
	Scrivete un programma che, dai due interi a e b in input, verifica se il
	più grande è quadrato o cubo del più piccolo.
*/
#include <stdio.h>

int main()
{
	// Prende in input due numeri interi.
	int a, b;
	printf("Inserisci due numeri interi: ");
	scanf("%d%d", &a, &b);
	
	// Se a è minore di b, allora scambia i due valori utilizzando lo XOR.
	if(a < b)
	{
		a = (a & ~b) | (b & ~a);
		b = (a & ~b) | (b & ~a);
		a = (a & ~b) | (b & ~a);
	}
	
	// Se il più grande è quadrato o cubo del più piccolo, stampa 'VERO'
	if((a == b * b) | (a == b * b * b))
		puts("VERO");
	else
		puts("FALSO");
	
	return 0;
}