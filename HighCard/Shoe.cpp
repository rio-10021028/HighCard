#include <iostream>
#include <cstdlib>
#include <algorithm>
#include "Shoe.h"
using namespace std;

// コンストラクタ
Shoe::Shoe()
{
	setDeck();
	shuffle();

	drawnCards = 0;
}

// 順番に初期化
void Shoe::setDeck()
{
	for (int i = 0; i < SUITS; i++)
	{
		for (int j = 0; j < NUMBERS; j++)
		{
			deck[i * NUMBERS + j].suit = static_cast<Suit>(i);
			deck[i * NUMBERS + j].number = static_cast<Number>(j);
		}
	}
}

// deck をシャッフル(フィッシャーイェーツ)
void Shoe::shuffle()
{
	int deckSize = sizeof(deck) / sizeof(deck[0]);
	for (int i = deckSize - 1; i > 1; i--)
	{
		int index = rand() % (i - 1);
		swap(deck[i], deck[index]);
	}
}

// deck の一番上を引いて、その情報を返す
Card Shoe::takeCard()
{
	// もし、52 枚引いていたら deck を作り直す
	if (drawnCards >= SUITS * NUMBERS)
	{
		setDeck();
		shuffle();
		drawnCards = 0;

		cout << "山札を引き切ったので、リセットしました。\n\n";
	}

	return deck[drawnCards++]; // drawnCards 枚目を引いた後、drawnCards を 1 増やす
}