#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Common.h"
#include "Player.h"
#include "Deck.h"
using namespace std;

// 乱数の初期化
void initRand()
{
	srand(static_cast<unsigned int>(time(nullptr)));
}

// 整数を入力させて返す関数
int inputInt(const char* message)
{
	// null チェック
	if (message == nullptr)
	{
		return -1;
	}

	int num;

	while (true)
	{
		cout << message << flush;

		if (cin >> num)
		{
			return num;
		}
		else
		{
			cout << "無効な入力です" << endl;

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
}

// 二つの整数を渡すと大きい方を返す関数
int compareInt(int num1, int num2)
{
	return (num1 > num2 ? num1 : num2);
}

// ゲーム本体の関数
void highCardGame(Player* p1, Player* p2, Deck* pdeck, Result* presult)
{
	// null チェック
	if (p1 == nullptr || p2 == nullptr || pdeck == nullptr || presult == nullptr)
	{
		return;
	}

	// number を決定
	p1->hit(pdeck);
	p2->hit(pdeck);

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
		cout << "draw";		// 同じなら引き分け
		presult->draw++;
	}
	else
	{
		// 結果比較
		int winnerValue = compareInt(p1->getNumber().card, p2->getNumber().card);

		cout << "winner > ";
		if (winnerValue == p1->getNumber().card)
		{
			p1->showName();
			presult->win++;
		}
		else
		{
			p2->showName();
			presult->lose++;
		}
	}
	cout << endl << endl;
}

int main()
{
	initRand();

	// 変数作成
	Player p1("Player 1");
	Player p2("Player 2");
	Deck deck;
	int round = 1;
	int battles;
	Result result =
	{
		0, 0, 0
	};

	// deck 準備
	deck.deckSet();
	deck.shuffle();

	// ゲーム関数呼び出し
	cout << "----- High Card Game -----\n\n";

	// 回数指定
	while (true)
	{
		battles = inputInt("何回戦にしますか > ");
		if (battles <= 0)
		{
			cout << "1 以上の値を入力してください" << endl;
		}
		else if(battles > 100)
		{
			cout << "数が大きいので 100 にしとくね\n\n";
			battles = 100;
			break;
		}
		else
		{
			cout << battles << " 回戦にします\n\n";
			break;
		}
	}

	// battles 回繰り返す
	for (; round <= battles; round++)
	{
		cout << "----- 第 " << round << " 回戦 -----\n\n";
		highCardGame(&p1, &p2, &deck, &result);
	}

	// 最終結果 表示
	cout << "===== 最終結果 =====" << endl;
	p1.showName();
	cout << " >" << endl << "勝ち > " << result.win << endl
		<< "負け > " << result.lose << endl
		<< "引き分け > " << result.draw << endl;
}