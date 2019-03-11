/*
	Si sviluppi una funzione che date due stringhe s e t elimini da s tutti i
	caratteri presenti in t.
*/
#include <stdio.h>
#include <string.h>

void elimina_caratteri(char stringa[], const char dictionary[]);

int main()
{
	char stringa1[] = "vincenzo";
	char stringa2[] = "in";

	elimina_caratteri(stringa1, stringa2);
	printf("%s\n", stringa1);

	return 0;
}

void elimina_caratteri(char stringa[], const char dictionary[])
{
	size_t k;

	for(size_t i = 0, j = 0; i <= strlen(stringa); i++)
	{
		for(k = 0; k < strlen(dictionary) && stringa[i] != dictionary[k]; k++);

		if(k == strlen(dictionary))
		{
			stringa[j] = stringa[i];
			j++;
		}
	}		
}
