/*
	Scrivere una funzione che date due stringhe s e t, e un intero k, minore della lunghezza
	della stringa s, inserisca, la stringa t in s a partire dal carattere k, spostando i
	caratteri nella stringa s a destra. Esempio s="Ciao caro", t="amico ", k = 4, la funzionà
	ritornerà s = "Ciao amico caro".
*/
#include <stdio.h>
#include <string.h>

void move(char s[], const char t[], size_t k);

int main()
{
	char s[100] = "Ciao caro";
	char t[100] = "amico ";
	int k;

	do
	{
		printf("Inserisci un numero intero positivo minore di %u: ", strlen(s));
		scanf("%d", &k);
	}
	while(k < 0 || k >= strlen(s));

	move(s, t, k);
	printf("%s\n", s);

	return 0;
}

void move(char s[], const char t[], size_t k)
{
	char buffer[1000];
	char* ptr = s + k + 1;

	strcpy(buffer, ptr);
	strcpy(ptr, t);
	strcat(s, buffer);
}
