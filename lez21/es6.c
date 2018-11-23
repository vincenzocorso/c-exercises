/*
	Scrivere un programma che data in input una stringa
	restituisca una nuova stringa con ogni carattere ripetuto
	due volte.
*/
#include <stdio.h>

void sdoppia_carattere(const unsigned int dimensione, const char stringa[], char risultato[]);

int main()
{
	char stringa[5] = "ciao";
	

	char risultato[10];	
	sdoppia_carattere(5, stringa, risultato);

	printf("%s\n", stringa2);

	return 0;
}

void sdoppia_carattere(const unsigned int dimensione, const char stringa[], char risultato[])
{
	for(unsigned int i = 0; i < dimensione * 2; i++)
		risultato[2 * i] = risultato[2 * i + 1] = stringa[i]; // assegnazione rapida

	return 0;
}
