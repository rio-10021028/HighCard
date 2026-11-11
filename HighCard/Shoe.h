#pragma once
#include "Common.h"

// Shoe クラス(デッキの情報を持つクラス)
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