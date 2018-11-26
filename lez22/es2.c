/*
	Scrivere un programma che data in input una stringa la
	copi in un’altra.
*/
#include <stdio.h>

void copia_stringa(const unsigned int dimensione, const char stringa[], char risultato[]);

int main()
{
	char stringa[5] = "Ciao";
	
	char risultato[5];
	copia_stringa(5, stringa, risultato);

	printf("%s\n", risultato);

	return 0;
}

void copia_stringa(const unsigned int dimensione, const char stringa[], char risultato[])
{
	for(unsigned int i = 0; i < dimensione; i++)
		risultato[i] = stringa[i];
}
