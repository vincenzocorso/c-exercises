/*
	Si scriva una funzione che trasforma una stringa di caratteri
	numerici nel corrispondente numero decimale.
*/
#include <stdio.h>
#include <math.h>

int converti_numero(const unsigned int dimensione, const char stringa[]);

int main()
{
	char stringa1[5] = "1234";
	char stringa2[5] = "5432";

	printf("%d\n", converti_numero(5, stringa1));
	printf("%d\n", converti_numero(5, stringa2));

	return 0;
}

int converti_numero(const unsigned int dimensione, const char stringa[])
{
	int multiplo, risultato = 0;

	for(unsigned int i = 0; i < dimensione; i++)
	{
		multiplo = pow(10, dimensione - 2 - i);
		risultato += (stringa[i] - '0') * multiplo; // esempio "1234" = 1*1000 + 2*100 + 3*10 + 4*1
	}

	return risultato;
}
