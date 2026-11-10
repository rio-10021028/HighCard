#pragma once

// 定数
const int SUITS = 4;
const int CARDS = 13;

// スートの列挙体
enum Suit
{
	Spades,
	Clubs,
	Hearts,
	Diamonds
};

// スートを表示するときの文字列(上の列挙体に対応)
// 実装部は Globals.cpp に
extern const char* suitNames[];

// カードの列挙体
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

// カードを表示する時の文字列(列挙体に対応)
// 実装部は Globals.cpp に
extern const char* cardNames[];

// カード情報を構造体に
struct CardInfo
{
	Suit suit;
	Card card;
};

// 結果保持の構造体
struct Result
{
	int win;
	int lose;
	int draw;
};

// yes or no(main.cpp 用)
enum Select
{
	No,
	Yes
};

// 乱数の初期化の関数
void initRand();

// 整数を入力させて返す関数
int inputInt(const char* message);