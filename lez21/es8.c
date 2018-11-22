/*
	Scrivere una funzione in C che data una stringa determini se essa è palindroma,
	ovvero se la sua lettura da sinistra verso destra o da destra verso sinistra
	produca la stessa stringa. Esempi di stringhe palindrome sono "anna", "osso",
	"ama". In particolare, la funzione deve ritornare 1 se la stringa è palindroma,
	zero altrimenti.
*/
#include <stdio.h>

unsigned char palindroma(const unsigned int dimensione, const char vettore[]);

int main()
{
	char stringa1[5] = "otto";
	char stringa2[6] = "otito";
	char stringa3[5] = "ciao";
	char stringa4[7] = "abcdba";
	char stringa5[8] = "ottetto";
	char stringa6[6] = "radar";

	printf("La stringa1 è palindroma? %u\n", palindroma(5, stringa1));
	printf("La stringa2 è palindroma? %u\n", palindroma(6, stringa2));
	printf("La stringa3 è palindroma? %u\n", palindroma(5, stringa3));
	printf("La stringa4 è palindroma? %u\n", palindroma(7, stringa4));
	printf("La stringa5 è palindroma? %u\n", palindroma(8, stringa5));
	printf("La stringa6 è palindroma? %u\n", palindroma(6, stringa6));

	return 0;
}

unsigned char palindroma(const unsigned int dimensione, const char vettore[])
{
	for(unsigned int i = 0; i < dimensione / 2; i++)
		if(vettore[i] != vettore[dimensione - i - 2])
			return 0;

	return 1;
}
