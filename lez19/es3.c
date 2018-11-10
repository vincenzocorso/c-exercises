/*
	Si scriva un programma in linguaggio C per poter analizzare
	una sequenza di numeri. Dati n numeri interi letti da tastiera
	si vogliono calcolare e stampare su schermo diversi risultati:
		- quanti sono i numeri positivi, nulli e negativi.
		- quanti sono i numeri pari e dispari
		- se la sequenza dei numeri inseriti è crescente, decrescente
		  oppure né crescente né decrescente.
*/
#include <stdio.h>

int main()
{
	// Prende in input il numero di interi che si vuole leggere.
	unsigned int numeri;
	printf("Inserisci il numero di interi che si vuole leggere da tastiera: ");
	scanf("%u", &numeri);

	// Ad ogni iterazione legge un intero e ne effettua un'analisi.
	int input, input_precedente;
	unsigned int positivi = 0, nulli = 0, dispari = 0;
	unsigned int crescente = 0, decrescente = 0;
	printf("Inserisci una sequenza di %d interi: ", numeri);
	for(unsigned int contatore = 1; contatore <= numeri; contatore++)
	{
		scanf("%d", &input);

		if(input > 0) // Se il numero è positivo
			positivi++;
		else if (!input) // Se il numero è nullo
			nulli++;

		if(input % 2) // Se il numero è pari
			dispari++;

		/* Alla prima iterazione non viene eseguito il confronto
		   perchè input_precedente non è ancora definito */
		if(input > input_precedente && contatore != 1)
			crescente++;
		else if(input < input_precedente && contatore != 1)
			decrescente++;

		input_precedente = input;
	}

	// Stampa il risultato
	printf("\nPositivi: %u\nNulli: %u\nNegativi: %u\n", positivi, nulli, numeri - positivi - nulli);
	printf("Pari: %u\nDispari: %u\n", numeri - dispari, dispari);
	
	if(crescente > 0 && !decrescente) // Se l'input è aumentato ogni volta
		printf("La sequenza è in ordine crescente.\n\n");
	else if(decrescente > 0 && !crescente) // Se l'input è diminuito ogni volta
		printf("La sequenza è in ordine descrescente.\n\n");
	else
		printf("La sequenza non è ordinata.\n\n");

	return 0;
}
