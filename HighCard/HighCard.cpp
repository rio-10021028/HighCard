#include <iostream>
#include <cstring>
#include <algorithm>
#include "HighCard.h"
#include "Dealer.h"
#include "Player.h"
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
void highCardGame(Participant* dealer, Participant* players, int sizeP, Shoe* pdeck, int* presults)
{
	// null チェック
	if (dealer == nullptr || players == nullptr || pdeck == nullptr || presults == nullptr)
	{
		return;
	}

	// number を決定
	dealer->hit(pdeck);
	for (int i = 0; i < sizeP; i++)
	{
		players[i].hit(pdeck);
	}

	// それぞれの number を表示(1, 11, 12, 13 は文字で表示)
	showCard(dealer);
	for (int i = 0; i < sizeP; i++)
	{
		showCard(&players[i]);
	}

	cout << "-----------------" << endl;
	// 勝者表示

	// 最大値を調べる
	Number maxValue = A;
	if (dealer->getCard().number >= maxValue)
	{
		maxValue = dealer->getCard().number;
	}

	for (int i = 0; i < sizeP; i++)
	{
		if (players[i].getCard().number >= maxValue)
		{
			maxValue = players[i].getCard().number;
		}
	}

	// 最大値と同じカードの人を数える
	int winnersNum = 0; // 勝者数(引き分けチェック用)
	if (dealer->getCard().number >= maxValue)
	{
		winnersNum++;
	}

	for (int i = 0; i < sizeP; i++)
	{
		if (players[i].getCard().number >= maxValue)
		{
			winnersNum++;
		}
	}

	// 引き分けチェック(全員同じ)
	if (winnersNum >= sizeP + 1)
	{
		presults[sizeP + 1]++; // 結果の配列の最後尾をインクリメント
	}
	else
	{
		cout << "winner > " << endl;
		if (dealer->getCard().number == maxValue)
		{
			dealer->showName();
			cout << endl;
			presults[0]++;
		}
		for (int i = 0; i < sizeP; i++)
		{
			if (players[i].getCard().number == maxValue)
			{
				players[i].showName();
				cout << endl;
				presults[i + 1]++;
			}
		}
	}
	cout << endl << endl;
}

// ゲーム進行の関数
void highCardGameSimulator()
{
	// 変数作成
	Shoe deck;
	int round = 1;
	int battles;

	// Dealer と player
	Dealer dealer;

	int numP = 2;

	// 人数入力ver.
	//while (true)
	//{
	//	int num = inputInt("Player の人数を入力してください > ");
	//	if (num <= 0)
	//	{
	//		cout << "0 以上で入力してください。" << endl;
	//	}
	//	else if (num <= 10)
	//	{
	//		cout << num << " 人にします。" << endl;
	//		numP = num;
	//		break;
	//	}
	//	else
	//	{
	//		cout << "多いので10 人にします。" << endl;
	//		numP = 10;
	//		break;
	//	}
	//}

	Player* players = new Player[numP];
	int* results = new int[numP + 2];// 勝ち数保持の配列(player 人数 + dealer[0] + 引き分け数用[最後尾])
	fill_n(results, numP + 2, 0); // 0 で埋めておく

	// Player の名前設定
	for (int i = 0; i < numP; i++)
	{
		cout << numP << " 人中 " << i + 1 << " 人目" << endl;
		players[i].setName();
	}

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
		highCardGame(&dealer, players, numP, &deck, results);
	}

	// 最終結果 表示
	cout << "===== 最終結果 =====" << endl
		<< "- 勝利数 -" << endl;
	dealer.showName();
	cout << " > " << results[0] << endl;
	for (int i = 0; i < numP; i++)
	{
		players[i].showName();
		cout << " > " << results[i + 1] << endl;
	}
	cout << "- 引き分け数 -" << endl
		<< results[numP + 1] << endl;

	// 解放
	delete[] players;
	delete[] results;
	players = nullptr;
	results = nullptr;
}