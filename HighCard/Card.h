#pragma once
#include "Common.h"

// カード情報のクラス
// operator== を持っている
class Card
{
public:
	Card();
	bool operator==(const Card& other) const;

public:
	Suit suit;
	Number number;
};