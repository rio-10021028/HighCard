#pragma once

// 定数
const int SUITS = 4;
const int CARDS = 13;

enum Suit
{
	Spades,
	Clubs,
	Hearts,
	Diamonds
};

extern const char* suitNames[];

enum Card
{
	A,
	TWO,
	THREE,
	FOUR,
	FIVE,
	SIX,
	SEVEN,
	EIGHT,
	NINE,
	TEN,
	J,
	Q,
	K
};

extern const char* cardNames[];

struct CardInfo
{
	Suit suit;
	Card card;
};

struct Result
{
	int win;
	int lose;
	int draw;
};