/*
	Esercizio 6
	Scrivere un programma che, dati in input due interi n e p maggiori di
	zero, verifichi se p è il più grande intero tale che p<=log2(n). Ad esempio
	dato n=10 e p=3 la risposta sarà VERO, dati 17 e 3 la risposta sarà
	FALSO. Risolvere il problema SENZA fare uso dell’elevazione a potenza.
*/
#include <stdio.h>

int main()
{
	// Prende in input due interi positivi.
	unsigned int n, p;
	printf("Inserisci due numeri interi maggiori di 0: ");
	scanf("%u%u", &n, &p);
	
	/* La disequazione logaritmica p <= log2(n), si può riscrivere come 2^p <= n.
	   Dato che p deve essere il più grande intero che verifica la relazione, dovrà essere:
	   i) 2^p <= n
	   ii) 2^(p+1) > n
	   Per eseguire l'elevamento a potenza utilizziamo lo shift a sinistra.
	   Se tali condizioni sono verificate, allora stampa 'VERO'. */
	if((1 << p <= n) && (1 << (p+1) > n))
		puts("VERO");
	else
		puts("FALSO");
	
	return 0;
}