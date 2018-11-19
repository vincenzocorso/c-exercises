/*
	Scrivere un programma che consenta di effettuare una tra
	le operazioni di somma, differenza, moltiplicazione e
	divisione tra due operandi, inserendo l’operazione da
	eseguire tramite uno tra i caratteri (‘+’, ‘-’, ‘*’, ‘/’) e i due
	operandi come numeri float. L’operazione deve essere
	eseguita se possibile.
*/
#include <stdio.h>

float esegui_operazione(const char operazione, const float numero1, const float numero2);

int main()
{
	float a, b;
	printf("Inserisci due numeri: ");
	scanf("%f%f", &a, &b);

	char operazione;
	printf("Inserisci l'operazione da effettuare (+ - * /): ");
	scanf(" %c", &operazione);

	printf("%.3f %c %.3f = %.3f\n", a, operazione, b, esegui_operazione(operazione, a, b));

	return 0;
}

float esegui_operazione(const char operazione, const float numero1, const float numero2)
{
	float risultato;
	
	switch(operazione)
	{
		case '+':
			risultato = numero1 + numero2;
			break;

		case '-':
			risultato = numero1 - numero2;
			break;

		case '*':
			risultato = numero1 * numero2;
			break;

		case '/':
			if(numero2)
				risultato = numero1 / numero2;
			break;
	}

	return risultato;
}
