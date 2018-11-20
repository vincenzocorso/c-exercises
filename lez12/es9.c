/*
	Esercizio 9
	Dato un intero b a 32 bit e un indice intero i, implementare un
	programma in C che, a richiesta dell’utente, ponga l’i-mo bit a zero, a
	uno, o lo complementi.
*/
#include <stdio.h>

// Definisce lo XOR come funzione macro.
#define XOR(a,b) (a & ~b) | (b & ~a)

int main()
{
	// Prende in input due numeri interi.
	int b, i;
	printf("Inserisci due numeri interi: ");
	scanf("%d%d", &b, &i);
	
	/* Prende in input un carattere che corrisponde all'azione da eseguire sull'i-esimo bit.
	   Zero: Z
	   Uno: U
	   Complemento: C */
	char c;
	printf("Operazione sul bit (Z - U - C): ");
	scanf(" %c", &c);
	
	/* Viene ignorata la differenza tra maiuscole e minuscole.
	   Viene creata una maschera di bit che congiunta alle operazioni di AND, OR, XOR
	   svolge quanto richiesto. */
	switch(c)
	{
		case 'z':
		case 'Z':
			printf("Risultato: %d\n", ~(1 << i) & b);
			break;
		
		case 'u':
		case 'U':
			printf("Risultato: %d\n", (1 << i) | b);
			break;
		
		case 'c':
		case 'C':
			printf("Risultato: %d\n", XOR((1 << i), b));
			break;
		
		default:
			puts("Carattere non valido");
			break;
	}
	
	return 0;
}
