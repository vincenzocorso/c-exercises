/*
	Scrivere un programma che data in input una stringa la
	copi in un’altra.
*/
#include <stdio.h>

int main()
{
	char stringa1[100];
	char stringa2[100];

	printf("Inserisci una stringa: ");
	fgets(stringa1, 100, stdin);

	for(unsigned int i = 0; i < 100; i++)
		stringa2[i] = stringa1[i];

	printf("%s\n", stringa2);

	return 0;
}
