/*
	Scrivere un programma che data in input una stringa
	trasformi i suoi caratteri minuscoli in maiuscoli.
*/
#include <stdio.h>

int main()
{
	char stringa[100];
	printf("Inserisci una stringa: ");
	fgets(stringa, 100, stdin); // fgets può prendere in input stringhe contenenti spazi

	const char offset = 'a' - 'A';
	for(char* ptr = stringa; *ptr != '\0'; ptr++)
		if(*ptr >= 'a' && *ptr <= 'z')
			*ptr -= offset;

	printf("%s\n", stringa);

	return 0;
}
