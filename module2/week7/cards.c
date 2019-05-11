#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CARDS	52
#define FACES	13
#define SUITS	4

typedef struct Card
{
	unsigned int face : 4;
	unsigned int suit : 2;
	unsigned int color : 1;
} Card;

typedef enum Face {ASSO, DUE, TRE, QUATTRO, CINQUE, SEI, SETTE, OTTO, NOVE, DIECI, JACK, DONNA, RE} Face;

void fill_deck(Card *Deck);
void shuffle_deck(Card *Deck);
void print_deck(Card *Deck, const char *faces[], const char *suits[]);

int main()
{
	srand(time(NULL));

	const char *faces[] = {"Asso", "Due", "Tre", "Quattro", "Cinque", "Sei", "Sette", "Otto", "Nove", "Dieci", "Jack", "Donna", "Re"};
	const char *suits[] = {"Cuori", "Picche", "Quadri", "Fiori"};
	
	Card Deck[CARDS];
	
	fill_deck(Deck);
	print_deck(Deck, faces, suits);
	
	puts("");
	shuffle_deck(Deck);
	print_deck(Deck, faces, suits);

	return 0;
}

void fill_deck(Card *Deck)
{
	for(int i = 0; i < CARDS; i++)
	{
		Deck[i].face = i % FACES;
		Deck[i].suit = i / FACES;
		Deck[i].color = i / (CARDS / 2);
	}
}

void shuffle_deck(Card *Deck)
{
	for(int i = 0; i < CARDS; i++)
	{
		int random = rand() % CARDS;
		if(i != random)
		{
			Card temp = Deck[i];
			Deck[i] = Deck[random];
			Deck[random] = temp;
		}
	}
}

void print_deck(Card *Deck, const char *faces[], const char *suits[])
{
	for(int i = 0; i < CARDS; i++)
		printf("%s di %s\n", faces[Deck[i].face], suits[Deck[i].suit]);
	puts("");
}
