/*
	Scrivere una funzione che data una stringa trovi il numero
	di occorrenze di un dato carattere.
*/
#include <stdio.h>

int occorrenze_carattere(const unsigned int dimensione, const char stringa[], const char carattere);

int main()
{
	char stringa[9] = "vincenzo";

	char carattere;
	printf("Inserisci un carattere da ricercare nella stringa: ");
	scanf("%c", &carattere);

	printf("Numero di occorrenze: %d\n", occorrenze_carattere(9, stringa, carattere));

	return 0;
}

int occorrenze_carattere(const unsigned int dimensione, const char stringa[], const char carattere)
{
	unsigned int contatore = 0;

	for(unsigned int i = 0; i < dimensione; i++)
		if(stringa[i] == carattere)
			contatore++;

	return contatore;			
}
