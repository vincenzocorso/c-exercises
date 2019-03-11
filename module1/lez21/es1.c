/*
	Scrivere una funzione in C che accetti come parametri in
	input un vettore di N elementi interi e un numero n di
	riferimento, e ritorni l’indice nell’array che contiene il
	numero altrimenti -1.
*/
#include <stdio.h>

int prendi_indice(const unsigned int dimensione, const int vettore[dimensione], const int valore);

int main()
{
	int vettore[10] = {5, 9, 3, 27, -5, 89, 2145, 0, 7, 23};

	int input;
	printf("Inserisci un numero intero: ");
	scanf("%d", &input);

	printf("L'indice dell'elemento %d è %d\n", input, prendi_indice(10, vettore, input));

	return 0;
}

int prendi_indice(const unsigned int dimensione, const int vettore[dimensione], const int valore)
{
	unsigned int indice = -1;

	for(unsigned int i = 0; i < dimensione && indice == -1; i++)
		if(vettore[i] == valore)
			indice = i;

	return indice;
}
