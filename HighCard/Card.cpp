#include <iostream>
#include "Card.h"
using namespace std;

// コンストラクタ
Card::Card()
{
	suit = Spades;
	number = A;
}

// 演算子オーバーロード(number のみを比較する)
// HighCard.cpp で使用
bool Card::operator==(const Card& other) const
{
	return number == other.number;
}