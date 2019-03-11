/*
	Si implementi un programma in C che simuli una rubrica telefonica. Ogni utente
	della rubrica è identificato dal suo nome e dal cognome. Si scriva una funzione
	in grado di ricercare un utente usando l'algoritmo di Ricerca Binaria (a tal fine
	la rubrica dovrà essere mantenuta in ordine).
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMERO		0
#define ETICHETTA	1

char*** menu(char ***rubrica, unsigned int *dimensione);
char*** inserisci(char ***rubrica, unsigned int *dimensione);
char*** elimina(char ***rubrica, unsigned int *dimensione, const unsigned int posizione);
void stampa_rubrica(char *** const rubrica, const unsigned int dimensione);
int ricerca_binaria(char *** const rubrica, const unsigned int dimensione, char *etichetta);

int main()
{
	char ***rubrica = NULL;
	unsigned int dimensione = 0;

	rubrica = menu(rubrica, &dimensione);

	/* Libera la memoria */
	for(unsigned int i = 0; i < dimensione; i++)
	{
		free(rubrica[dimensione][NUMERO]);
		free(rubrica[dimensione][ETICHETTA]);
		free(rubrica[dimensione]);
	}
	free(rubrica);

	return 0;
}

char*** menu(char ***rubrica, unsigned int *dimensione)
{
	int scelta, input;
	char stringa[31];

	do
	{
		puts("\n\n\n\t\tRUBRICA TELEFONICA");
		puts("Che operazione vuoi effettuare?");
		puts("0. Crea contatto");
		puts("1. Elimina contatto");
		puts("2. Cerca contatto");
		puts("3. Stampa rubrica");
		puts("4. Esci dal programma");
		printf("--> ");
		scanf("%u", &scelta);

		switch(scelta)
		{
			case 0: // Crea contatto
				puts("\n\nCREA CONTATTO");
				rubrica = inserisci(rubrica, dimensione);
				break;

			case 1: // Elimina contatto
				puts("\n\nELIMINA CONTATTO");
				do
				{
					printf("Inserisci il numero identificativo del contatto che vuoi eliminare: ");
					scanf("%u", &input);
				}
				while(input >= *dimensione);
				rubrica = elimina(rubrica, dimensione, input);
				break;

			case 2: // Cerca contatto
				printf("Inserisci il nome e il cognome del contatto che vuoi cercare (formato Nome Cognome): ");
				getchar(); // Pulisce il buffer dello stdin. Altrimenti gets non funziona.
				gets(stringa);

				input = ricerca_binaria(rubrica, *dimensione, stringa);
				input = (input >= *dimensione || strcmp(rubrica[input][ETICHETTA], stringa) != 0) ? -1 : input;

				if(input != -1)
					printf("E' stata trovata una corrispondenza.\nN°%d | %s --> %s\n", input, rubrica[input][ETICHETTA], rubrica[input][NUMERO]);
				else
					puts("Non è stata trovata alcuna corrispondenza.");
				break;

			case 3: // Stampa rubrica
				puts("\n\nLISTA CONTATTI");
				stampa_rubrica(rubrica, *dimensione);
				break;

			default: // Esci dal programma
				break;
		}
	}
	while(scelta < 4);

	return rubrica;
}

char*** inserisci(char ***rubrica, unsigned int *dimensione)
{
	/* Alloca la memoria necessaria per una matrice n x 2 */
	rubrica = (char ***)realloc(rubrica, (*dimensione + 1) * sizeof(char **)); // Aumenta di 1 il numero di contatti
	rubrica[*dimensione] = (char **)malloc(2 * sizeof(char *)); // Alloca lo spazio per due puntatori (numero, etichetta)
	rubrica[*dimensione][NUMERO] = (char *)malloc(11 * sizeof(char)); // Alloca lo spazio per la stringa contenente il numero
	rubrica[*dimensione][ETICHETTA] = (char *)malloc(31 * sizeof(char)); // Alloca lo spazio per la stringa contenente il nome

	/* Prende i dati in input e li inserisce nella rubrica */
	char numero[11], etichetta[31];
	getchar(); // Pulisce il buffer dello stdin. Altrimenti gets non funziona.
	printf("Inserisci il numero di telefono: ");
	gets(numero); // gets non funziona
	printf("Inserisci il nome e il cognome (formato 'Nome Cognome'): ");
	gets(etichetta);

	/* Effettua una ricerca binaria per valutare la posizione di inserimento */
	int indice = ricerca_binaria(rubrica, *dimensione, etichetta);

	/* Sposta tutti gli elementi da indice a dimensione - 1 verso destra */
	for(unsigned int i = *dimensione; i > indice; i--)
	{
		strcpy(rubrica[i][NUMERO], rubrica[i - 1][NUMERO]);
		strcpy(rubrica[i][ETICHETTA], rubrica[i - 1][ETICHETTA]);
	}

	/* Inserisci il nuovo elemento in posizione indice */
	strcpy(rubrica[indice][NUMERO], numero);
	strcpy(rubrica[indice][ETICHETTA], etichetta);

	/* Aumenta la dimensione dell'array */
	*dimensione = *dimensione + 1;

	return rubrica;
}

char*** elimina(char ***rubrica, unsigned int *dimensione, const unsigned int posizione)
{
	/* Sposta tutti gli elementi dopo posizione verso sinista */
	for(unsigned int i = posizione; i < *dimensione - 1; i++)
	{
		strcpy(rubrica[i][NUMERO], rubrica[i + 1][NUMERO]);
		strcpy(rubrica[i][ETICHETTA], rubrica[i + 1][ETICHETTA]);
	}

	/* Libera la memoria */
	free(rubrica[*dimensione - 1][NUMERO]);
	free(rubrica[*dimensione - 1][ETICHETTA]);
	free(rubrica[*dimensione - 1]);

	*dimensione = *dimensione - 1;

	return rubrica;
}

void stampa_rubrica(char *** const rubrica, const unsigned int dimensione)
{
	for(unsigned int i = 0; i < dimensione; i++)
		printf("N°%d | %s --> %s\n", i, rubrica[i][ETICHETTA], rubrica[i][NUMERO]);
}

int ricerca_binaria(char *** const rubrica, const unsigned int dimensione, char *etichetta)
{
	if(!dimensione) // Se l'array è vuoto ritorna indice 0
		return 0;

	int sx = 0, dx = dimensione - 1, cx, confronto;
	while(sx < dx)
	{
		cx = (sx + dx) / 2;
		confronto = strcmp(etichetta, rubrica[cx][ETICHETTA]);

		if(confronto > 0)
			sx = cx + 1;
		else if(confronto < 0)
			dx = cx - 1;
		else
			sx = dx = cx;
	}

	return ((strcmp(etichetta, rubrica[sx][ETICHETTA]) > 0) ? sx + 1 : sx);
}
