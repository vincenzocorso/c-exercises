/*
	Scrivere una funzione che date due stringhe s e t calcoli il numero di
	occorrenze di t in s, ovvero, ritorni il numero di volte in cui t è
	completamente contenuta in s.
*/
#include <stdio.h>
#include <string.h>

int occorrenza_stringa(const char stringa[], const char ricerca[]);

int main()
{
	char stringa1[29] = "Ciaooooociaociaoocaccioaciao";
	char stringa2[5] = "ciao";

	printf("Il numero di occorrenze di %s in %s è %d.\n", stringa2, stringa1, occorrenza_stringa(stringa1, stringa2));

	return 0;
}

int occorrenza_stringa(const char stringa[], const char ricerca[])
{
	unsigned int occorrenza = 0;

	for(size_t i = 0, j = 0; i < strlen(stringa); i++)
	{
		if(stringa[i] == ricerca[j])
		{
			j++;

			if(j == strlen(ricerca))
			{
				j = 0;
				occorrenza++;
			}
		}
	}

	return occorrenza;	
}
