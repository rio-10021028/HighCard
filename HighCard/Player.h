#pragma once
#include "Common.h"
#include "Participant.h"

// Player クラス(Participant クラスを継承)
class Player:
	public Participant
{
public:
	Player(const char* pname);	// 引数付きコンストラクタ
};