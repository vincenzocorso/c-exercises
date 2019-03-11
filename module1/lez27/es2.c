/*
	Si scriva un programma che dato un numero N in input dia la
	possibilità all'utente di inserire N stringhe. Si definisca
	una funzione che prenda come input le N stringhe e restituisca
	un vettore di interi V tale per cui
		V[i] = 1 se le stringhe di posizione i e i+1 sono in ordine crescente
		V[i] = -1 se le stringhe di posizione i e i+1 sono in ordine decrescente
		V[i] = 0 se le stringhe di posizione i e i+1 sono uguali
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inserisci_stringhe(char* vettore[], const size_t dimensione);
int* stato_ordinamento(char* const vettore[], const size_t dimensione);
void stampa_vettore(const int vettore[], const size_t dimensione);

int main()
{
	unsigned int N;
	printf("Quante stringhe vuoi inserire? ");
	scanf("%u", &N);

	char* stringhe[N]; // Array che contiene le stringhe
	int* ordinamento; // Array che contiene l'ordine del vettore di stringhe
	inserisci_stringhe(stringhe, N); // Riempe l'array con delle stringhe inserite dall'utente
	ordinamento = stato_ordinamento(stringhe, N); // Inserisce l'ordine degli elementi nel vettore
	stampa_vettore(ordinamento, N - 1);

	// Libera la memoria
	free(ordinamento);
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

int* stato_ordinamento(char* const vettore[], const size_t dimensione)
{
	int* risultato = (int*)calloc(dimensione - 1, sizeof(int));

	int confronto;
	for(size_t i = 0; i < dimensione - 1; i++)
	{
		confronto = strcmp(vettore[i], vettore[i+1]);

		if(confronto < 0)
			risultato[i] = 1;
		else if(confronto > 0)
			risultato[i] = -1;
		else
			risultato[i] = 0;
	}

	return risultato;
}

void stampa_vettore(const int vettore[], const size_t dimensione)
{
	for(size_t i = 0; i < dimensione; i++)
		printf("%d ", vettore[i]);

	printf("\n");
}
