/*
	Si scriva un programma che dato un numero N in input dia la
	possibilità all'utente di inserire N stringhe. Si definisca
	una funzione che prenda come input le N stringhe e restituisca
	un intero che assume il valore 1 se le stringhe sono ordinate
	in modo crescente, -1 se le stringhe sono ordinate in modo
	crescente, 0 se le stringhe non rispettano alcune ordine.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inserisci_stringhe(char* vettore[], const size_t dimensione);
int ordine_stringhe(char* vettore[], const size_t dimensione);

int main()
{
	unsigned int N;
	printf("Quante stringhe vuoi inserire? ");
	scanf("%u", &N);

	char* stringhe[N];
	inserisci_stringhe(stringhe, N);
	switch(ordine_stringhe(stringhe, N))
	{
		case 1:
			printf("Le stringhe sono ordinate in maniera decrescente.\n");
			break;

		case -1:
			printf("Le stringhe sono ordinate in maniera crescente.\n");
			break;

		default:
			printf("Le stringhe non sono ordinate\n");
			break;
	}

	for(size_t i = 0; i < N; i++)
		free(stringhe[i]);

	return 0;
}

void inserisci_stringhe(char* vettore[], const size_t dimensione)
{
	for(size_t i = 0; i < dimensione; i++)
	{
		printf("Inserisci la %d° stringa (limite 100 caratteri): ", i+1);
		vettore[i] = (char*)calloc(100, sizeof(char));
		scanf("%s", vettore[i]);
	}
}

int ordine_stringhe(char* vettore[], const size_t dimensione)
{
	int ordine=0, confronto;
	for(size_t i = 0; i < dimensione - 1; i++)
	{
		confronto = strcmp(vettore[i], vettore[i+1]);

		if(confronto * ordine < 0) // se sono discordi, non sono ordinati
			return 0;
		else if(confronto <= 0)
			ordine = -1;
		else
			ordine = 1;
	}

	return ordine;
}
