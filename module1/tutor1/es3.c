/*
	Si scriva un programma che dato un numero N in input dia la possibilità
	all'utente di inserire N stringhe. Si definisca una funzione ordina_stringhe(V, n, t)
	che ordini le stringhe in ordine lessicografico crescente se t=0 e in ordine
	lessicografico decrescente se t = 1.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** inserisci_stringhe(char **stringhe, int *dimensione);
void ordina_stringhe(char **stringhe, const unsigned int dimensione, const int t);
int minmax(char **stringhe, const unsigned int n, const int t);
void swap(char *a, char *b);
void stampa_stringhe(char **stringhe, int dimensione);

int main()
{
	/* Dichiara un vettore di stringhe */
	char **stringhe = NULL;
	unsigned int dimensione = 0;

	/* Prende in input le N stringhe dall'utente */
	unsigned int N;
	printf("Quante stringhe vuoi inserire? ");
	scanf("%u", &N);

	for(unsigned int i = 0; i < N; i++)
		stringhe = inserisci_stringhe(stringhe, &dimensione);

	ordina_stringhe(stringhe, N, 0);

	puts("L'array adesso è:");
	stampa_stringhe(stringhe, N);

	return 0;
}

char** inserisci_stringhe(char **stringhe, int *dimensione)
{
	stringhe = (char **)realloc(stringhe, (*dimensione + 1) * sizeof(char *));
	stringhe[*dimensione] = (char *)malloc(100 * sizeof(char));

	printf("Inserisci la stringa N°%d: ", *dimensione);
	scanf("%s", stringhe[*dimensione]);

	*dimensione = *dimensione + 1;
	
	return stringhe;
}

void ordina_stringhe(char **stringhe, const unsigned int dimensione, const int t)
{
	int index;
	for(unsigned int i = 0; i < dimensione - 1; i++)
	{
		index = minmax(stringhe, dimensione - 1 - i, t);
		swap(stringhe[index], stringhe[dimensione - 1 - i]);
	}
}

int minmax(char **stringhe, const unsigned int n, const int t)
{
	int index = 0, confronto;

	for(unsigned int i = 1; i <= n; i++)
	{
		confronto = strcmp(stringhe[i], stringhe[index]);

		if(t == 1 && confronto < 0)
			index = i;
		else if(t == 0 && confronto > 0)
			index = i;
	}

	return index;
}

void swap(char *a, char *b)
{
	char temp[100];
	strcpy(temp, a);
	strcpy(a, b);
	strcpy(b, temp);
}

void stampa_stringhe(char **stringhe, int dimensione)
{
	for(unsigned int i = 0; i < dimensione; i++)
		printf("%s\n", stringhe[i]);
}
