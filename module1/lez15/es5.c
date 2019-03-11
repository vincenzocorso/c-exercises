/*
	Scrivere un programma che, dati in ingresso due numeri positivi x e y
	visualizza in ordine decrescente la sequenza di numeri interi compresi
	tra x e y che sono divisibili per il minore tra x e y. Ad esempio, se x = 5
	e y = 38, la sequenza è 35,30,25,20,15,10,5.
*/
#include <stdio.h>

int main()
{
	// Prende in input un numero intero positivo.
	unsigned int x, y;
	printf("Inserisci due numeri interi positivi: ");
	scanf("%u%u", &x, &y);

	// Ottengo, tra i numeri inseriti, il massimo e il minimo.
	unsigned int min = y, max = x;
	if(y > x)
	{
		min = x;
		max = y;
	}

	/* Imposto il valore iniziale al più grande numero appartenente
	   all'intervallo divisibile per min (esempio --> 35). Per fare
	   ciò imposto: i = max - (max % min)
	   Fatto ciò gli altri numeri sarano sfasati di min.
	   Esempio: 35 - 5 --> 30 - 5 --> 25 - 5 --> 20 ..*/
	for(unsigned int i = max - (max % min); i >= min; i -= min)
		printf("%u\n", i);

	return 0;
}
