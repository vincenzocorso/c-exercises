#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_ACCOUNTS	"accounts.dat"

typedef struct account
{
	int id;
	char username[20];
	char password[20];
} account;
typedef account *account_ptr;

void create_account(int id, char username[], char password[]);
void delete_account(int id);
void get_account(int id, account_ptr a);
void print_account(account_ptr a);

int main()
{
	create_account(0, "vincenzo", "corso");
	create_account(1, "a", "b");
	create_account(2, "c", "d");

	account a, b, c;
	get_account(0, &a);
	get_account(1, &b);
	get_account(2, &c);

	print_account(&a);
	puts("");
	print_account(&b);
	puts("");
	print_account(&c);
	puts("");

	delete_account(1);

	get_account(0, &a);
	get_account(1, &b);
	get_account(2, &c);
	print_account(&a);
	puts("");
	print_account(&b);
	puts("");
	print_account(&c);
	puts("");

	return 0;
}

void create_account(int id, char username[], char password[])
{
	FILE *file = fopen(FILE_ACCOUNTS, "rb+");
	if(file == NULL) file = fopen(FILE_ACCOUNTS, "wb");

	if(file != NULL)
	{
		account_ptr a = malloc(sizeof(account));
		if(a != NULL)
		{
			a->id = id;
			strcpy(a->username, username);
			strcpy(a->password, password);

			fseek(file, id * sizeof(account), SEEK_SET);
			fwrite(a, sizeof(account), 1, file);
		}

		fclose(file);
	}
	else puts("Impossibile aprire il file di salvataggio.");
}

void delete_account(int id)
{
	FILE *file = fopen(FILE_ACCOUNTS, "rb+");
	if(file != NULL)
	{
		account a = {-1, "", ""};
		fseek(file, id * sizeof(account), SEEK_SET);
		fwrite(&a, sizeof(account), 1, file);	
		fclose(file);	
	}
	else puts("Impossibile aprire il file di salvataggio.");
}

void get_account(int id, account_ptr a)
{
	FILE *file = fopen(FILE_ACCOUNTS, "rb+");
	if(file != NULL)
	{
		fseek(file, id * sizeof(account), SEEK_SET);
		fread(a, sizeof(account), 1, file);
		fclose(file);
	}
	else puts("Impossibile aprire il file di salvataggio.");
}

void print_account(account_ptr a)
{
	printf("Account id: %d\nUsername: %s\nPassword: %s\n", a->id, a->username, a->password);
}
