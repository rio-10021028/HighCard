#include <iostream>
#include "Participant.h"
using namespace std;

// コンストラクタ
Participant::Participant()
{
	// name を 初期化
	name = "ななし";

	// number を初期化
	number.suit = Spades;
	number.card = A;
}

//deck から1 枚引いてその情報を保持
void Participant::hit(Shoe* pdeck)
{
	// null チェック
	if (pdeck == nullptr)
	{
		return;
	}

	number = pdeck->takeCard();
}

//保持しているカードの情報を返す
CardInfo Participant::getNumber() const
{
	return number;
}

// 保持しているカードのスートを表示する関数
void Participant::showSuit() const
{
	cout << suitNames[number.suit];
}

//保持しているカードの数を表示する関数
void Participant::showNumber() const
{
	cout << cardNames[number.card];
}

// 名前を表示する関数
void Participant::showName() const
{
	cout << name;
}