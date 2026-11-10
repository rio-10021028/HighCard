#include <iostream>
#include "Player.h"
using namespace std;

// 引数付きコンストラクタ
Player::Player(const char* pname)
{
	// name を渡された名前で初期化
	name = pname;

	// その他初期化
	number.suit = Spades;
	number.card = A;
}
