/*
	Si scriva un programma che dato un numero N in input dia la possibilità
	all'utente di inserire N stringhe. Si crei un menù che dia la possibilità
	all'utente di eseguire le seguenti operazione sulle stringhe immesse:
		1) Aggiungere un ulteriore stringa;
		2) Trovare la stringa di lunghezza maggiore;
		3) Trovare la stringa di lunghezza minore;
		4) Cancellare una stringa
		5) Ricercare una stringa
		6) Individuare gli indici delle stringhe che contengono la parola P definita dall'utente.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inizializzazione(char ***stringhe, size_t *dimensione);
void menu(char ***stringhe, size_t *dimensione);
void inserisci_stringa(char ***stringhe, size_t *dimensione);
char* max_stringa(char ** const stringhe, const size_t dimensione);
char* min_stringa(char ** const stringhe, const size_t dimensione);
void cancella_stringa(char ***stringhe, size_t *dimensione, size_t posizione);
int ricerca_stringa(char ** const stringhe, size_t dimensione, const char *stringa);
void ricerca_parola(char ** const stringhe, size_t dimensione, const char *stringa);
void stampa_stringhe(char ** const stringhe, const size_t dimensione);

int main()
{
	size_t N = 0;
	char **stringhe = NULL;

	/* Fase di inizializzazione */
	inizializzazione(&stringhe, &N);

	/* Visualizza il menù */
	menu(&stringhe, &N);

	/* Libera la memoria */
	for(size_t i = 0; i < N; i++)
		free(stringhe[i]);
	free(stringhe);

	return 0;
}

void inizializzazione(char ***stringhe, size_t *dimensione)
{
	/* Chiede all'utente il numero di stringhe che vuole inserire
	   all'avvio del programma */
	unsigned int numero;
	puts("\t\t| SEQUENZA DI AVVIO |");
	printf("Quante stringhe vuoi inserire?\n--> ");
	scanf("%u", &numero);

	/* Prende in input delle stringhe e le inserisce nell'array */
	for(unsigned int i = 0; i < numero; i++)
		inserisci_stringa(stringhe, dimensione);
}

void menu(char ***stringhe, size_t *dimensione)
{
	unsigned int scelta, input;
	char stringa[100];

	do
	{
		puts("\n\n\n\t\tMenu");
		puts("Che operazioni vuoi effettuare?");
		puts("1. Aggiungere un ulteriore stringa");
		puts("2. Trovare la stringa di lunghezza maggiore");
		puts("3. Trovare la stringa di lunghezza minore");
		puts("4. Cancellare una stringa");
		puts("5. Ricercare una stringa");
		puts("6. Trovare le stringhe che contengono una certa parola");
		puts("7. Stampare tutte le stringhe inserite");
		puts("8. Uscire dal programma");
		printf("--> ");
		scanf("%u", &scelta);

		switch(scelta)
		{
			case 1: // Aggiungere un ulteriore stringa
				puts("\n\n\n| INSERISCI NUOVA STRINGA |");
				inserisci_stringa(stringhe, dimensione);
				break;

			case 2: // Trovare la stringa di lunghezza maggiore
				puts("\n\n\n| STRINGA DI LUNGHEZZA MAGGIORE |");
				puts("La stringa di lunghezza maggiore è:");
				printf("%s\n", max_stringa(*stringhe, *dimensione));
				break;

			case 3: // Trovare la stringa di lunghezza minore
				puts("\n\n\n| STRINGA DI LUNGHEZZA MINORE |");
				puts("La stringa di lunghezza minore è:");
				printf("%s\n", min_stringa(*stringhe, *dimensione));
				break;

			case 4: // Cancellare una stringa
				puts("\n\n\n| CANCELLA STRINGA |");
				printf("Inserisci il numero della stringa che vuoi cancellare: ");
				scanf("%u", &input);
				if(input <= *dimensione - 1)
					cancella_stringa(stringhe, dimensione, input);
				break;

			case 5: // Ricercare una stringa
				puts("\n\n\n| RICERCA STRINGA |");
				puts("Digita la stringa che vuoi ricercare:");
				printf("--> ");
				scanf("%s", stringa);
				printf("La stringa %s presente nell'array.\n", (ricerca_stringa(*stringhe, *dimensione, stringa) == 1) ? "è" : "non è");
				break;

			case 6: // Trovare le stringhe che contengono una certa parola
				puts("\n\n\n| RICERCA PAROLA |");
				puts("Digita la parola che vuoi ricercare nell'array:");
				printf("--> ");
				scanf("%s", stringa);
				puts("È stata trovata una corrispondenza in tali stringhe:");
				ricerca_parola(*stringhe, *dimensione, stringa);
				break;

			case 7: // Stampare tutte le stringhe inserite
				puts("\n\n\n| STRINGHE INSERITE |");
				stampa_stringhe(*stringhe, *dimensione);
				break;
		}
	}
	while(scelta > 0 && scelta < 8);
}

void inserisci_stringa(char ***stringhe, size_t *dimensione)
{
	/* Alloca la memoria necessaria per aggiungere una nuova stringa */
	*stringhe = (char**)realloc(*stringhe, (*dimensione + 1) * sizeof(char*));
	(*stringhe)[*dimensione] = (char*)malloc(100 * sizeof(char));

	/* Prende in input la stringa e la inserisce nell'array */
	printf("Stringa N°%u --> ", *dimensione);
	scanf("%s", (*stringhe)[*dimensione]);

	/* Aggiorna il contatore nel numero delle stringhe all'intero dell'array */	
	*dimensione = *dimensione + 1;
}

char* max_stringa(char ** const stringhe, const size_t dimensione)
{
	/* Imposta la prima stringa come massima */
	size_t index_max = 0, max = strlen(stringhe[0]);

	/* Ricerca la stringa di lunghezza maggiore */
	for(size_t i = 1, lenght; i < dimensione; i++)
	{
		lenght = strlen(stringhe[i]);
		if(lenght > max)
		{
			max = lenght;
			index_max = i;
		}
	}

	/* Ritorna la stringa di lunghezza maggiore */
	return stringhe[index_max];
}

char* min_stringa(char ** const stringhe, const size_t dimensione)
{
	/* Imposta la prima stringa come minima */
	size_t index_min = 0, min = strlen(stringhe[0]);

	/* Ricerca la stringa di lunghezza minore */
	for(size_t i = 1, lenght; i < dimensione; i++)
	{
		lenght = strlen(stringhe[i]);
		if(lenght < min)
		{
			min = lenght;
			index_min = i;
		}
	}

	/* Ritorna la stringa di lunghezza minore */
	return stringhe[index_min];
}

void cancella_stringa(char ***stringhe, size_t *dimensione, size_t posizione)
{
	/* Trasla tutti gli elementi dopo posizione, verso sinista */
	for(size_t i = posizione; i < *dimensione - 1; i++)
		strcpy((*stringhe)[i], (*stringhe)[i+1]);

	/* Libera la memoria dell'ultimo elemento che non serve più */
	free((*stringhe)[*dimensione - 1]);
	*stringhe = (char**)realloc(*stringhe, (*dimensione - 1) * sizeof(char*));
	*dimensione = *dimensione - 1; 
}

int ricerca_stringa(char ** const stringhe, size_t dimensione, const char *stringa)
{
	int flag = 0;

	/* Confronta tutte le stringhe dell'array con quella presa in input */
	for(size_t i = 0; i < dimensione && !flag; i++)
		if(strcmp(stringhe[i], stringa) == 0)
			flag = 1;

	return flag;
}

void ricerca_parola(char ** const stringhe, size_t dimensione, const char *stringa)
{
	/* Cerca all'intero delle stringhe la parola presa in input */
	for(size_t i = 0; i < dimensione; i++)
		if(strstr(stringhe[i], stringa) != NULL)
			printf("Stringa N°%u --> %s\n", i, stringhe[i]);			
}

void stampa_stringhe(char **const stringhe, const size_t dimensione)
{
	/* Stampa tutte le stringhe presenti nell'array */
	for(size_t i = 0; i < dimensione; i++)
		printf("Stringa N°%u --> %s\n", i, stringhe[i]);
}
