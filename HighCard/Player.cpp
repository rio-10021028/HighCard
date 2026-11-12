#include <iostream>
#include <cstring>
#include "Player.h"
using namespace std;

// 引数付きコンストラクタ
Player::Player(const char* pname)
{
	// null チェック
	if (pname == nullptr)
	{
		name = new char[1]; // 辻褄を合わせるため、こちらでも new する
		name = "\0";
	}
	else
	{
		// 渡された名前をコピーして name を初期化
		size_t length = strlen(pname);
		char* newName = new char[length + 1];
		strcpy_s(newName, length + 1, pname);

		name = newName;
	}

	// その他初期化
	number.suit = Spades;
	number.number = A;
}

// デストラクタ
Player::~Player()
{
	delete[] name;
}