#include <iostream>
#include "Participant.h"
using namespace std;

// コンストラクタ
Participant::Participant()
{
	// name を 初期化
	name = "ななし";

	// number を初期化
	card.suit = Spades;
	card.number = A;
}

//deck から1 枚引いてその情報を保持
void Participant::hit(Shoe* pdeck)
{
	// null チェック
	if (pdeck == nullptr)
	{
		return;
	}

	card = pdeck->takeCard();
}

//保持しているカードの情報を返す
Card Participant::getCard() const
{
	return card;
}

// 保持しているカードのスートを表示する関数
void Participant::showSuit() const
{
	cout << suitNames[card.suit];
}

//保持しているカードの数を表示する関数
void Participant::showNumber() const
{
	cout << numberNames[card.number];
}

// 名前を表示する関数
void Participant::showName() const
{
	cout << name;
}