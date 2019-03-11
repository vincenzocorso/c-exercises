/* Scrivere un programma che, dato un intero N, facendo uso
di una funzione di nome primo, visualizzi tutti gli interi minori
di N che sono primi. */
#include <stdio.h>
#include <math.h>

void primo(int numero);

int main()
{
	unsigned int n;
	printf("Inserisci un numero intero positivo: ");
	scanf("%u", &n);

	primo(n);

	return 0;
}

void primo(int numero)
{
	for(unsigned int i = 2; i < numero; i++)
	{
		unsigned int flag = 1;
		for(unsigned int d = 2; d <= sqrt(i) && flag; d++)
		{
			if(!(i % d))
				flag = 0;
		}
		
		if(flag)
			printf("%u\n", i);
	}
}
