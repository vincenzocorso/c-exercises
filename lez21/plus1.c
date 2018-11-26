/*
	Scrivere una funzione in linguaggio C che dato in ingresso un vettore
	di n numeri interi visualizza in output una riga di asterischi per
	ogni elemento del vettore, il cui numero è uguale al valore
	dell'elemento nel vettore.
*/
#include <stdio.h>

void visualizza_vettore(unsigned int dimensione, int vettore[]);

int main()
{
	int vettore[5] = {5, 3, 9, 4, 2};

	visualizza_vettore(5, vettore);

	return 0;
}

void visualizza_vettore(unsigned int dimensione, int vettore[])
{
	for(unsigned int i = 0; i < dimensione; i++)
	{
		printf("Elemento %u: ", i); 

		for(unsigned j = 0; j < vettore[i]; j++)
			printf("*");

		printf("\n");
	}
}
