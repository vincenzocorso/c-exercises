/*
	Scrivere un programma determini la media di una sequenza di
	numeri non negativi immessi dall’utente terminata con -1;
*/
#include <stdio.h>

int main()
{
	float input, somma = 0.0;
	unsigned int contatore = 0; // Contiene il numero degli input inseriti dall'utente

	do
	{
		printf("Inserisci un numero intero positivo (-1 per terminare): ");
		scanf("%f", &input);

		if(input >= 0)
		{
			somma += input;
			contatore++;
		}
	}
	while(input != -1);

	printf("La media è %f.\n", somma / contatore);
	
	return 0;
}
