#pragma once
#include "Common.h"
#include "Shoe.h"

class Participant
{
public:
	Participant();
	void hit(Shoe* pdeck);
	Card getNumber() const;
	void showSuit() const;
	void showNumber() const;
	void showName() const;	// name を表示

protected:
	const char* name;
	Card number;
};