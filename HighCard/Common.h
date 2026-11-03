#pragma once

const int SUITS = 4;
const int CARDS = 13;

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

enum Suit
{
	Spades,
	Clubs,
	Hearts,
	Diamonds
};

extern const char* suitNames[];

struct CardInfo
{
	Suit suit;
	Card card;
};