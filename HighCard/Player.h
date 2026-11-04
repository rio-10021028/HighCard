#pragma once
#include "Common.h"
#include "Deck.h"

class Player
{
public:
	Player(const char* pname);
	void hit(Deck* cdeck);
	CardInfo getNumber() const;
	void showSuit() const;
	void showNumber() const;
	void showName() const;	// name を表示

private:
	const char* name;
	CardInfo number;
};