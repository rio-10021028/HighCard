#include <iostream>
#include "HighCard.h"
using namespace std;

// 宿題指定の関数(アップキャストで Player クラスか
// Dealer クラスを渡すと、名前とカード情報を表示)
void showCard(const Participant* participant)
{
	// null チェック
	if (participant == nullptr)
	{
		return;
	}

	participant->showName();
	cout << " > ";
	participant->showSuit();
	cout << " の ";
	participant->showNumber();
	cout << endl;
}

// ゲーム本体の関数
void highCardGame(Participant* dealer, Participant* player, Shoe* pdeck, Result* presult)
{
	// null チェック
	if (dealer == nullptr || player == nullptr || pdeck == nullptr || presult == nullptr)
	{
		return;
	}

	// number を決定
	dealer->hit(pdeck);
	player->hit(pdeck);

	// それぞれの number を表示(1, 11, 12, 13 は文字で表示)
	showCard(dealer);
	showCard(player);

	// 勝者表示
	cout << "-----------------" << endl;
	if (dealer->getNumber().number == player->getNumber().number)
	{
		cout << "draw";		// 同じなら引き分け
		presult->draw++;
	}
	else
	{
		// 結果比較
		int winnerValue = max(dealer->getNumber().number, player->getNumber().number);

		cout << "winner > ";
		if (winnerValue == player->getNumber().number)
		{
			player->showName();
			presult->win++;
		}
		else
		{
			dealer->showName();
			presult->lose++;
		}
	}
	cout << endl << endl;
}

// ゲーム進行の関数
void highCardGameSimulator()
{
	// 変数作成
	Dealer dealer;
	Player player("Player");
	Shoe deck;
	int round = 1;
	int battles;
	Result result =
	{
		0, 0, 0
	};

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
		highCardGame(&dealer, &player, &deck, &result);
	}

	// 最終結果 表示
	cout << "===== 最終結果 =====" << endl;
	player.showName();
	cout << " >" << endl << "勝ち > " << result.win << endl
		<< "負け > " << result.lose << endl
		<< "引き分け > " << result.draw << endl;
}