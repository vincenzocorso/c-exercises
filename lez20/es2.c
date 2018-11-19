/*
	Legge tre interi e stabilire se possono essere le lunghezze
	dei lati di un triangolo. In caso affermativo, trova la
	tipologia del triangolo.
*/
#include <stdio.h>

void stampa_tipologia_triangolo(const unsigned int a, const unsigned int b, const unsigned int c);

int main()
{
	unsigned int a, b, c;
	printf("Inserisci tre numeri interi positivi: ");
	scanf("%u%u%u", &a, &b, &c);

	stampa_tipologia_triangolo(a, b, c);

	return 0;
}

void stampa_tipologia_triangolo(const unsigned int a, const unsigned int b, const unsigned int c)
{
	if(a < b + c && a > b - c)
	{
		if(a == b && b == c)
			printf("È un triangolo equilatero.\n");
		else if(a != b && a != c && b != c)
			printf("È un triangolo scaleno.\n");
		else
			printf("È un triangolo isoscele.\n");
	}
	else printf("Non è un triangolo.\n");
}
