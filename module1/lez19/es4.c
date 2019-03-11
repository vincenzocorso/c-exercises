/*
	Scrivere una funzione in linguaggio C che stampi i primi N
	numeri della successione di Fibonacci, con N inserito da tastiera.
*/
#include <stdio.h>

void stampa_fibonacci(unsigned int numero);

int main()
{
	unsigned int n;
	printf("Inserisci un numero intero positivo: ");
	scanf("%u", &n);

	stampa_fibonacci(n);	

	return 0;
}

void stampa_fibonacci(unsigned int numero)
{
	unsigned int a = 0, b = 1;
	
	for(unsigned int i = 1; i <= numero; i++)
	{
		printf("%u\n", b);
		b = a + b;
		a = b - a;
	}
}


