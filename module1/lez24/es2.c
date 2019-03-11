/*
	Scrivere una funzione che chieda all’utente di immettere un testo fino
	alla parola “fine.” e che dopo lo visualizzi.
*/
#include <stdio.h>
#include <string.h>

void inserisci_testo(const char stop[]);

int main()
{
	puts("Inserisci un testo che termina con \"fine.\":");
	inserisci_testo("fine.");

	return 0;
}

void inserisci_testo(const char stop[])
{
	char flag = 1, dest[1000] = "", input[1000];
	char* ptr;

	while(flag)
	{
		fgets(input, 1000, stdin); //fgets prende anche \n.
		ptr = input + strlen(input) - strlen(stop) - 1; //punta alla n-ultimo carattere. Serve per verificare se l'utente ha inserito "fine."
		input[strlen(input) - 1] = '\0'; //Sostituisco lo \n con \0
		strcat(dest, input); // concatenza la stringa inserita a dest
		if(strcmp(ptr, stop) == 0) // quando viene inserito fine. esce dal ciclo.
			flag = 0;
	}

	printf("\ntesto inserito:\n%s\n", dest);
}
