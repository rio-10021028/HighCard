#pragma once
#include "Common.h"
#include "Player.h"
#include "Dealer.h"
#include "Shoe.h"

// 二つの整数を渡すと大きい方を返す関数
int compareInt(int num1, int num2);

// 宿題指定の関数(アップキャストで Player クラスか
// Dealer クラスを渡すと、名前とカード情報を表示)
void showCardInfo(Participant* participant);

// ゲーム本体の関数
void highCardGame(Participant* dealer, Participant* player, Shoe* pdeck, Result* presult);

// ゲーム進行の関数
void highCardGameSimulator();