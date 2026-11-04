#pragma once
#include "Common.h"

class Deck
{
public:
	Deck();
	void deckSet();
	void shuffle();
	CardInfo draw();

private:
	CardInfo deck[SUITS * CARDS];
	int drawnCards;
};