#pragma once
#include "Common.h"
#include "Participant.h"

// Player クラス
class Player:
	public Participant
{
public:
	Player(const char* pname);
};