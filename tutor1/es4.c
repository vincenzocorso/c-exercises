/*
	Data una stringa confrontare il numero di parole e stampare
	la parola di lunghezza maggiore.
*/
#include <stdio.h>
#include <string.h>

void token(char * const string, int *number, char max[]);

int main()
{
	char string[100] = "ciao mi chiamo vincenzo";

	int number = 0;
	char max[100] = "";	
	token(string, &number, max);

	printf("Numero di parole: %d\nParola più lunga: %s\n", number, max);

	return 0;
}

void token(char * const string, int *number, char max[])
{
	char *ptr = string; // Punta alla prima lettera di ogni parola
	char temp[100] = ""; // Contiene la parola appena scansionata

	for(unsigned int i = 0, j = 1; i <= strlen(string); i++, j++)
	{
		if(string[i] == ' ' || string[i] == '\0') // Lo \0 indica che è finita la parola situata alla fine.
		{
			strncpy(temp, ptr, j - 1);
			temp[j] = '\0';
			
			/* Se la parola scansionata è più lunga della maggiore
			attualmente trovata, aggiorna max */
			if(strlen(temp) > strlen(max))
				strcpy(max, temp);

			*number = *number + 1;
			ptr = ptr + j;
			j = 0;
		}
	}
}
