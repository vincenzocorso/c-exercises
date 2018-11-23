/*
	Scrivere un programma che data in input una stringa
	trasformi i suoi caratteri minuscoli in maiuscoli.
*/
#include <stdio.h>

void trasforma_in_maiuscolo(const int dimensione, const char stringa[], char risultato[]);

int main()
{
	char stringa[5] = "Ciao";

	char risultato[5];
	trasforma_in_maiuscolo(5, stringa, risultato);

	printf("%s\n", risultato);

	return 0;
}

void trasforma_in_maiuscolo(const int dimensione, const char stringa[], char risultato[])
{
	const char offset = 'a' - 'A';
	for(unsigned int i = 0; i < dimensione; i++)
		risultato[i] = (stringa[i] >= 'a' && stringa[i] <= 'z') ? stringa[i] - offset : stringa[i];
}
