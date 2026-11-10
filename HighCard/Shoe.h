#pragma once
#include "Common.h"

class Shoe
{
public:
	Shoe();
	void deckSet();
	void shuffle();
	CardInfo takeCard();

private:
	CardInfo deck[SUITS * CARDS];
	int drawnCards;
};