/*
	Scrivere una funzione che data una stringa conti il numero
	di lettere maiuscole.
*/
#include <stdio.h>

int numero_maiuscole(const unsigned int dimensione, const char striga1[]);

int main()
{
	char stringa1[5] = "ciao";
	char stringa2[5] = "CIao";
	char stringa3[9] = "VINceNZO";

	printf("%s --> %d\n", stringa1, numero_maiuscole(5, stringa1));
	printf("%s --> %d\n", stringa2, numero_maiuscole(5, stringa2));
	printf("%s --> %d\n", stringa3, numero_maiuscole(9, stringa3));

	return 0;
}

int numero_maiuscole(const unsigned int dimensione, const char stringa1[])
{
	unsigned int risultato = 0;
	for(unsigned int i = 0; i < dimensione; i++)
		if(stringa1[i] >= 'A' && stringa1[i] <= 'Z')
			risultato++;

	return risultato;
}
