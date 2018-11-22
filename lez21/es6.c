/*
	Scrivere un programma che data in input una stringa
	restituisca una nuova stringa con ogni carattere ripetuto
	due volte.
*/
#include <stdio.h>

int main()
{
	char stringa1[50];
	char stringa2[100];

	fgets(stringa1, 100, stdin);
	
	for(unsigned int i = 0; i < 50; i += 1)
		stringa2[2 * i] = stringa2[2 * i + 1] = stringa1[i];

	printf("%s\n", stringa2);

	return 0;
}
