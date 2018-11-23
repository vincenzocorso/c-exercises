/*
	Scrivere una funzione che dato un testo trasformi in maiuscole
	le lettere dopo il punto.
*/
#include <stdio.h>

void trasforma_maiuscole(const unsigned int dimensione, const char stringa1[], char risultato[]);

int main()
{
	char stringa1[14] = "ciao.vincenzo";
	char stringa2[14] = "ciao.vINcenzo";

	char risultato[100];
	trasforma_maiuscole(14, stringa1, risultato);
	printf("%s -> %s\n", stringa1, risultato);

	trasforma_maiuscole(14, stringa2, risultato);
	printf("%s -> %s\n", stringa2, risultato);

	return 0;
}

void trasforma_maiuscole(const unsigned int dimensione, const char stringa1[], char risultato[])
{
	int flag = 0, offset = 'a' - 'A';

	for(unsigned int i = 0; i < dimensione; i++)
	{
		if(flag && stringa1[i] >= 'a' && stringa1[i] <= 'z')
			risultato[i] = stringa1[i] - offset;
		else
		{
			risultato[i] = stringa1[i];

			if(stringa1[i] == '.')
				flag = 1;
		}
	}
}


