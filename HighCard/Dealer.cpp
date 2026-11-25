#include <iostream>
#include "Dealer.h"

// コンストラクタ
Dealer::Dealer()
{
	// name を "Dealer" で初期化
	name = "Dealer";

	// number を初期化
	card.suit = Spades;
	card.number = A;
}

//deck から2 枚引いて、大きい方を保持
void Dealer::hit(Shoe* pdeck)
{
	// null チェック
	if (pdeck == nullptr)
	{
		return;
	}

	// 2 枚引く
	Card takenCard1 = pdeck->takeCard();
	Card takenCard2 = pdeck->takeCard();

	// Card クラスより、演算子オーバーロード(>=)を使用
	card = (takenCard1 >= takenCard2 ? takenCard1 : takenCard2);
}