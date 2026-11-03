#include <iostream>
#include <algorithm>
#include "Deck.h"
using namespace std;

Deck::Deck()
{
	for (int i = 0; i < SUITS; i++)
	{
		for (int j = 0; j < CARDS; j++)
		{
			deck[i * CARDS + j].suit = static_cast<Suit>(i);
			deck[i * CARDS + j].card = static_cast<Card>(j);
		}
	}
}

void Deck::shuffle()
{
	int deckSize = sizeof(deck) / sizeof(deck[0]);
	for (int i = deckSize - 1; i > 1; i--)
	{
		int index = rand() % (i - 1);
		swap(deck[i], deck[index]);
	}
}

CardInfo Deck::draw()
{
	return deck[drawnCards++];
}

CardInfo* Deck::get()
{
	return deck;
}