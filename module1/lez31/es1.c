/*
	Si supponga di avere un file di testo di nome “vettore.txt” che viene
	usato per memorizzare un vettore di reali. Più precisamente, il file
	contiene dei numeri reali in formato testo suddivisi da uno spazio.
	Ad esempio:
	0.52 3.2 1.13 2.01 10.12 -7.3
	Vogliamo scrivere un programma che legge dal file di testo e inserisce
	ogni elemento come float in un vettore V.
	Usare fgets e sscanf.
*/
#include <stdio.h>
#include <stdlib.h>

void stampa_vettore(const double *vettore, const unsigned int dimensione);

int main()
{
	/* Dichiarazione del vettore che contiene i valori letti dal file */
	double *vettore = NULL;
	unsigned int dimensione = 0;

	/* Apertura del file in modalita read (lettura) */
	FILE *fptr = fopen("vettore.txt", "r");
	if(fptr != NULL)
	{
		double input;
		
		/* Continua a leggere finché non viene raggiunta la fine del file*/
		while(fscanf(fptr, "%lf", &input) != EOF)
		{
			vettore = (double *)realloc(vettore, (dimensione + 1) * sizeof(double));
			vettore[dimensione] = input;
			dimensione++;
		}

		/* Chiude il file */
		fclose(fptr);

		/* Stampa il vettore e libera la memoria */
		stampa_vettore(vettore, dimensione);
		free(vettore);
	}
	else puts("Impossibile aprire il file \"vettore.txt\".");

	return 0;
}

void stampa_vettore(const double *vettore, const unsigned int dimensione)
{
	for(unsigned int i = 0; i < dimensione; i++)
		printf("%f ", vettore[i]);

	puts("");
}
