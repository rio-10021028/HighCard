#include <iostream>
#include "Player.h"
using namespace std;

// コンストラクタ
Player::Player(const char* pname)
{
	// name に代入(null チェック)
	if (pname == nullptr)
	{
		name = "ななし";
	}
	else
	{
		name = pname;
	}

	// number を初期化
	number.suit = Spades;
	number.card = A;
}

//deck から1 枚引いてその情報を保持
void Player::hit(Deck* cdeck)
{
	// null チェック
	if (cdeck == nullptr)
	{
		return;
	}

	number = cdeck->draw();
}

//保持しているカードの情報を返す
CardInfo Player::getNumber() const
{
	return number;
}

// 保持しているカードのスートを表示する関数
void Player::showSuit() const
{
	cout << suitNames[number.suit];
}

//保持しているカードの数を表示する関数
void Player::showNumber() const
{
	cout << cardNames[number.card];
}

// プレイヤーの名前を表示する関数
void Player::showName() const
{
	cout << name;
}