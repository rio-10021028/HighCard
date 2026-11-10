#pragma once
#include "Common.h"
#include "Player.h"
#include "Dealer.h"
#include "Shoe.h"

// 二つの整数を渡すと大きい方を返す関数
int compareInt(int num1, int num2);

// 宿題の要件の関数
void showCardInfo(Participant* participant);

// ゲーム本体の関数
void highCardGame(Participant* dealer, Participant* player, Shoe* pdeck, Result* presult);

// ゲーム進行の関数
void highCardGameSimulator();