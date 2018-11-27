/*
	Scrivere una funzione che date due stringhe s e t ritorni nella seconda
	la prima letta da destra verso sinistra.
*/
#include <stdio.h>
#include <string.h>

void inverti(const char stringa1[], char stringa2[]);

int main()
{
	char s[9] = "vincenzo";
	char t[9] = "";

	inverti(s, t);
	printf("%s\n", t);

	return 0;
}

void inverti(const char stringa1[], char stringa2[])
{
	for(int i = strlen(stringa1) - 1; i >= 0; i--)
		stringa2[strlen(stringa1) - i - 1] = stringa1[i];

	stringa2[strlen(stringa1)] = '\0';
}
