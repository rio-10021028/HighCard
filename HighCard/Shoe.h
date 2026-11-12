#pragma once
#include "Common.h"
#include "Card.h"

// Shoe クラス(デッキの情報を持つクラス)
class Shoe
{
public:
	Shoe();
	Card takeCard();

private:
	void setDeck();
	void shuffle();

private:
	Card deck[SUITS * NUMBERS];
	int drawnCards;
};