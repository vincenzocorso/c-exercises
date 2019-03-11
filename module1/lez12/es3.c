/*
	Esercizio 3
	Scrivere un programma che, dati in input tre numeri interi a,b,c,
	risolva l’equazione di secondo grado ax^2+bx+c=0, ovvero ne calcoli e
	visualizzi le soluzioni (se esistono).
*/
#include <stdio.h>
#include <math.h>

int main()
{
	// Prende in input tre numeri interi positivi.
	int a, b, c;
	printf("Inserisci tre numeri interi: ");
	scanf("%d%d%d", &a, &b, &c);
	
	if(a == 0) // Se è un'equazione di primo grado, stampa la soluzione.
		printf("x = %f", -c / b);
	else
	{
		double delta = sqrt(b * b - 4.0 * a * c);
		
		if(delta >= 0.0) // Se l'equazione ammette soluzioni nei reali, stampa le due soluzioni.
			printf("x1 = %f | x2 = %f\n", (-b - delta) / (2.0 * a), (-b + delta) / (2.0 * a));
		else
			printf("Non sono presenti soluzioni nei reali\n");
	}
	
	return 0;
}