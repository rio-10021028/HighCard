#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Player.h"
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

	// number を決定
	p1->hit();
	p2->hit();

	// それぞれの number を表示(1, 11, 12, 13 は文字で表示)
	p1->showName();
	cout << " > ";
	switch (p1->getNumber())
	{
	case 1:
		cout << "A";
		break;
	case 11:
		cout << "J";
		break;
	case 12:
		cout << "Q";
		break;
	case 13:
		cout << "K";
		break;
	default:
		p1->showNumber();
	}
	cout << endl;

	p2->showName();
	cout << " > ";
	switch (p2->getNumber())
	{
	case 1:
		cout << "A";
		break;
	case 11:
		cout << "J";
		break;
	case 12:
		cout << "Q";
		break;
	case 13:
		cout << "K";
		break;
	default:
		p2->showNumber();
	}
	cout << endl << endl;

	// 勝者表示
	cout << "-----------------" << endl;
	if (p1->getNumber() == p2->getNumber())
	{
		cout << "draw" << endl;		// 同じなら引き分け
	}
	else
	{
		// 結果比較
		int winnerValue = compareInt(p1->getNumber(), p2->getNumber());

		cout << "winner > ";
		winnerValue == p1->getNumber() ? p1->showName() : p2->showName();
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