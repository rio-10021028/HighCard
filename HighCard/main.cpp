#include <iostream>
#include "Common.h"
#include "HighCard.h"
using namespace std;

int main()
{
	// 乱数の初期化
	initRand();

	// リプレイのループ用のフラグ
	bool inputFlag = false;

	// ゲーム実行
	while (true)
	{
		// ゲーム呼び出し
		highCardGameSimulator();
		cout << endl << "*~~~~~*~~~~~*~~~~~*~~~~~*~~~~~*~~~~~*\n\n";

		// リプレイの入力のループ
		while (!inputFlag)
		{
			cout << "yes > 1" << endl
				<< "no  > 0" << endl;
			switch (inputInt("もう一度やりますか？ > "))
			{
			case Yes:	// 入力のループを抜ける
				inputFlag = true;
				break;
			case No:	// main 関数を終わる
				return 0;
			default:	// もう一度ループ
				cout << "1 か 0 で入力してください。" << endl;
				break;
			}
		}

		inputFlag = false; // 次のループのために false にしておく
		cout << endl;
	}

}