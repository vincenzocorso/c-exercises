//==========[FUNZIONI GENERALI]==========

//	Questa funzione scambia il contenuto di due variabili intere
void swap(int* numero1, int* numero2);

//==========[FUNZIONI MATEMATICHE]==========

//	Calcola l'mcd tra due interi positivi, utilizzando l'algoritmo di Euclide
unsigned int mcd_euclide(unsigned int numero1, unsigned int numero2);

//	Calcola l'mcd tra due interi positivi, utilizzando il metodo della differenza
unsigned int mcd_differenza(unsigned int numero1, unsigned int numero2);

//	Calcola l'mcd tra due interi positivi, utilizzando la definizione classica
unsigned int my_mcd(unsigned int numero1, unsigned int numero2);

//	Calcola l'mcm tra due interi positivi, utilizzando la definizione classica
unsigned int my_mcm(unsigned int numero1, unsigned int numero2);

//	Controlla se il numero inserito è primo
char primo(unsigned int numero);

//	Calcola il fattoriale del numero n
unsigned long long int fattoriale(unsigned int numero);

//	Stampa i primi n numeri della successione di fibonacci
void stampa_fibonacci(unsigned int numero);
