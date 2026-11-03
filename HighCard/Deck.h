#pragma once
#include "Common.h"

class Deck
{
public:
	Deck();
	void shuffle();
	CardInfo draw();
	CardInfo* get(); // 外から変えないの意味で、参照渡しにする？

private:
	CardInfo deck[SUITS * CARDS];
	int drawnCards = 0;
};