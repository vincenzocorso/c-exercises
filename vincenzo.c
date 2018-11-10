#include <stdio.h>

#define XOR(A,B) (A & ~B) | (B & ~A)

void swap(int* numero1, int* numero2)
{
	*numero1 = XOR(*numero1, *numero2);
	*numero2 = XOR(*numero1, *numero2);
	*numero1 = XOR(*numero1, *numero2);
}

unsigned int mcd_euclide(unsigned int numero1, unsigned int numero2)
{
	if(numero2 > numero1)
		swap(&numero1, &numero2);

	unsigned int resto;
	while(numero2)
	{
		resto = numero1 % numero2;
		numero1 = numero2;
		numero2 = resto;
	}

	return numero1;
}

unsigned int mcd_differenza(unsigned int numero1, unsigned int numero2)
{
	while(numero1 != numero2)
	{
		if(numero1 > numero2)
			numero1 = numero1 - numero2;
		else
			numero2 = numero2 - numero1;
	}

	return numero1;
}

unsigned int my_mcd(unsigned int numero1, unsigned int numero2)
{
	if(numero2 < numero1)
		swap(&numero1, &numero2);

	unsigned int mcd;
	for(mcd = numero1; numero1 % mcd || numero2 % mcd; mcd--);

	return mcd;
}

unsigned int my_mcm(unsigned int numero1, unsigned int numero2)
{
	if(numero2 < numero1)
		swap(&numero1, &numero2);

	unsigned int mcm;
	for(mcm = numero1; mcm % numero1 || mcm % numero2; mcm++);

	return mcm;
}

char primo(unsigned int numero)
{
	unsigned int i;
	for(i = 2; i < numero && numero % i; i++);

	return (i == numero); //1 se vero oppure 0 se falso 
}

unsigned long long int fattoriale(unsigned int numero)
{
	unsigned long long int risultato = 1;
	for(; numero > 1 ; numero--)
		risultato *= numero;

	return risultato;
}

void stampa_fibonacci(unsigned int numero)
{
	unsigned int a = 0, b = 1;
	
	for(unsigned int i = 1; i <= numero; i++)
	{
		printf("%u\n", b);
		b = a + b;
		a = b - a;
	}
}
