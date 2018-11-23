/*
	Scrivere una funzione che date due stringhe ne stabilisca
	l'ordine lessicografico.
*/
#include <stdio.h>

int ordine_lessicografico(const unsigned int dimensione1, const char stringa1[], const unsigned int dimensione2, const char stringa2[]);

int main()
{
	char stringa1[5] = "cIao";
	char stringa2[7] = "ciCCio";
	char stringa3[7] = "Ciaone";
	char stringa4[9] = "vINcenzo";

	printf("%s | %s --> %d\n", stringa1, stringa2, ordine_lessicografico(5, stringa1, 7, stringa2));
	printf("%s | %s --> %d\n", stringa1, stringa3, ordine_lessicografico(5, stringa1, 7, stringa3));
	printf("%s | %s --> %d\n", stringa1, stringa4, ordine_lessicografico(5, stringa1, 9, stringa4));
	printf("%s | %s --> %d\n", stringa4, stringa2, ordine_lessicografico(9, stringa4, 7, stringa2));
	printf("%s | %s --> %d\n", stringa4, stringa3, ordine_lessicografico(9, stringa4, 7, stringa3));
	printf("%s | %s --> %d\n", stringa4, stringa1, ordine_lessicografico(9, stringa4, 5, stringa1));
	printf("%s | %s --> %d\n", stringa4, stringa4, ordine_lessicografico(9, stringa4, 9, stringa4));

	return 0;
}

/*
	La funzione ritorna i seguenti valori:
	1 --> la prima stringa viene prima della seconda
	0 --> le due stringhe sono uguali
	-1 --> la prima stringa viene dopo la seconda
*/
int ordine_lessicografico(const unsigned int dimensione1, const char stringa1[], const unsigned int dimensione2, const char stringa2[])
{
	unsigned int min = dimensione1;
	if(dimensione2 < min)
		min = dimensione2;

	char flag = 0;
	for(unsigned int i = 0; i < min && flag == 0; i++)
	{
		if(stringa1[i] < stringa2[i])
			flag = 1;
		else if(stringa1[i] > stringa2[i])
			flag = -1;
	}

	return flag;
}
