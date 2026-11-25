#pragma once
#include "Common.h"
#include "Shoe.h"

class Participant
{
public:
	Participant();
	virtual void hit(Shoe* pdeck) = 0; // 純粋仮想関数
	Card getCard() const;
	void showSuit() const;
	void showNumber() const;
	void showName() const;	// name を表示

protected:
	const char* name;
	Card card;
};