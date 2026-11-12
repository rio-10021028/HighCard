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