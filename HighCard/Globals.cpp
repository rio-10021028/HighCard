#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// suitNames と cardNames の実装部分
const char* suitNames[] =
{
	"スペード",
	"クラブ  ",
	"ハート  ",
	"ダイヤ  ",
};

const char* numberNames[] =
{
	"A",
	"2",
	"3",
	"4",
	"5",
	"6",
	"7",
	"8",
	"9",
	"10",
	"J",
	"Q",
	"K",
};

// 乱数の初期化の関数
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