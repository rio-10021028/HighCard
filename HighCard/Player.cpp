#include <iostream>
#include "Player.h"
using namespace std;

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
	number = 0;
}

//内部で乱数により数を決定して保持
void Player::hit()
{
	number = (rand() % 13) + 1;		// 0～13 を代入
}

//内部で決定した数を返す
int Player::getNumber()
{
	return number;
}

void Player::showNumber()
{
	cout << number;
}

void Player::showName()
{
	cout << name;
}