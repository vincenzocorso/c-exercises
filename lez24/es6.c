/*
	Scrivere una funzione che, data una stringa s la renda palindroma inserendovi
	un numero minimo di caratteri. Ad esempio, la stringa "Ab3bd" si può trasformare
	in palindroma inserendo due caratteri ("dAb3bAd" o "Adb3bdA"). La stringa "dAbdbd"
	inserendo 1 carattere "dAbdbAd").
*/
#include <stdio.h>
#include <string.h>

void aggiungi_carattere(char stringa[], const size_t posizione, const char carattere);
int cerca_in_sottostringa(const char stringa[], const size_t start, const size_t end, const char carattere);
void rendi_palindroma(char stringa[]);

int main()
{
	char stringa1[100] = "Ab3bd";
	printf("%s --> ", stringa1);
	rendi_palindroma(stringa1);
	printf("%s\n", stringa1);

	char stringa2[100] = "dAbdbd";
	printf("%s --> ", stringa2);
	rendi_palindroma(stringa2);
	printf("%s\n", stringa2);

	char stringa3[100] = "ciaovincenzo";
	printf("%s --> ", stringa3);
	rendi_palindroma(stringa3);
	printf("%s\n", stringa3);

	return 0;
}

void aggiungi_carattere(char stringa[], const size_t posizione, const char carattere)
{
	char buffer[1000];
	char* ptr = stringa + posizione;
	
	strcpy(buffer, ptr);
	stringa[posizione] = carattere;
	strcpy(ptr + 1, buffer);
}

int cerca_in_sottostringa(const char stringa[], const size_t start, const size_t end, const char carattere)
{
	size_t index = -1;

	for(size_t i = start; i <= end && index == -1; i++)
		if(stringa[i] == carattere)
			index = i;

	return index;
}

void rendi_palindroma(char stringa[])
{
	for(size_t i = 0; i < strlen(stringa) / 2; i++)
	{
		size_t lenght = strlen(stringa);

		if(stringa[i] != stringa[lenght - i - 1])
		{
			int found = cerca_in_sottostringa(stringa, i + 1, lenght - i - 2, stringa[i]);

			if(found != -1)
				aggiungi_carattere(stringa, i, stringa[lenght - i - 1]);
			else
				aggiungi_carattere(stringa, lenght - i, stringa[i]);
		}
	}
}
