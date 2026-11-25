#include <iostream>
#include <cstring>
#include "Player.h"
using namespace std;

// 引数付きコンストラクタ
Player::Player()
{
	name = new char[1]; // setName と辻褄を合わせるため、ここでも new する
	name = "\0";

	// その他初期化
	card.suit = Spades;
	card.number = A;
}

void Player::setName()
{
	// 名前をコピーして name を初期化
	char inputName[32];

	cout << "このプレイヤーの名前を入力してください > " << flush;
	cin >> inputName;

	size_t length = strlen(inputName);
	char* newName = new char[length + 1];
	strcpy_s(newName, length + 1, inputName);

	name = newName;
}

// デストラクタ
Player::~Player()
{
	delete[] name;
}

//deck から1 枚引いてその情報を保持
void Player::hit(Shoe* pdeck)
{
	// null チェック
	if (pdeck == nullptr)
	{
		return;
	}

	card = pdeck->takeCard();
}