/*
	Si scriva una funzione che prenda in input una matrice di caratteri (ogni riga
	sarà una stringa che è stata inserita in input precedentemente dall'utente) e gli
	indici i1, i2, j1 e j2. La funzione dovrà restituire una stringa creata dalla
	concatenazione dei primi n caratteri (caratteri da posizione 0 a posizione j1 + 1)
	della stringa di posizione i1 e degli ultimi m caratteri (dalla posizione j2 alla
	fine della stringa) della stringa di posizione i2. Si propongano delle soluzioni per
	la gestione delle diverse lunghezze delle stringhe all'interno della matrice.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *stringa_crossover(char **stringhe, unsigned int i1, unsigned int i2, unsigned int j1, unsigned int j2);

int main()
{
	/* Chiede all'utente il numero di stringhe */
	unsigned int N;
	printf("Quante stringhe vuoi inserire? ");
	scanf("%u", &N);

	/* Dichiarazione dell'array che conterrà le stringhe */
	char **matrice = (char**)malloc(N * sizeof(char *));
	for(unsigned int i = 0; i < N; i++)
		matrice[i] = (char *)malloc(100 * sizeof(char));

	/* Riempie l'array con le stringhe prese in input */
	for(unsigned int i = 0; i < N; i++)
	{
		printf("Inserisci la stringa N°%u --> ", i);
		scanf("%s", matrice[i]);
	}

	/* Prende in input i quattro indici */
	unsigned int i1, i2, j1, j2;
	printf("Inserisci quattro interi positivi: ");
	scanf("%u%u%u%u", &i1, &i2, &j1, &j2);

	/* Crea la nuova stringa e la stampa */
	char *output = stringa_crossover(matrice, i1, i2, j1, j2);
	printf("%s\n", output);

	/* Libera la memoria */
	for(unsigned int i = 0; i < N; i++)
		free(matrice[i]);
	free(matrice);
	free(output);

	return 0;
}

char *stringa_crossover(char **stringhe, unsigned int i1, unsigned int i2, unsigned int j1, unsigned int j2)
{
	/* Controlla se gli indici sono maggiori della dimensione della stringa */
	if(j1 > strlen(stringhe[i1]))
		j1 = strlen(stringhe[i1]);
	if(j2 > strlen(stringhe[i2]))
		j2 = strlen(stringhe[i2]);

	/* Alloca la memoria per la stringa che sarà ritornata alla fine */
	char *output = (char *)calloc(j1 + 3 + strlen(stringhe[i2]) - j2, sizeof(char));

	/* Crea la nuova stringa */
	strncat(output, stringhe[i1], j1 + 2); // strncat a differenza dello strncpy, aggiunge automaticamente lo \0
	strcat(output, &stringhe[i2][j2]);

	return output;
}
