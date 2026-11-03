#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Common.h"
#include "Player.h"
#include "Deck.h"
using namespace std;

void initRand()
{
	srand(static_cast<unsigned int>(time(nullptr)));
}

// 二つの整数を渡すと大きい方を返す関数
int compareInt(int num1, int num2)
{
	return (num1 > num2 ? num1 : num2);
}

// ゲーム本体の関数
void highCardGame(Player* p1, Player* p2)
{
	// null チェック
	if (p1 == nullptr || p2 == nullptr)
	{
		return;
	}

	Deck deck;
	deck.shuffle();

	// number を決定
	p1->hit(deck);
	p2->hit(deck);

	// それぞれの number を表示(1, 11, 12, 13 は文字で表示)
	p1->showName();
	cout << " > ";
	p1->showSuit();
	cout << " の ";
	p1->showNumber();
	cout << endl;

	p2->showName();
	cout << " > ";
	p2->showSuit();
	cout << " の ";
	p2->showNumber();
	cout << endl;

	// 勝者表示
	cout << "-----------------" << endl;
	if (p1->getNumber().card == p2->getNumber().card)
	{
		cout << "draw" << endl;		// 同じなら引き分け
	}
	else
	{
		// 結果比較
		int winnerValue = compareInt(p1->getNumber().card, p2->getNumber().card);

		cout << "winner > ";
		winnerValue == p1->getNumber().card ? p1->showName() : p2->showName();
		cout << endl;
	}
}

int main()
{
	initRand();

	// 変数作成
	Player p1("Player 1");
	Player p2("Player 2");

	// ゲーム関数呼び出し
	cout << "----- High Card Game -----\n\n";
	highCardGame(&p1, &p2);
}