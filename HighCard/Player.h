#pragma once
#include "Participant.h"

// Player クラス(Participant クラスを継承)
class Player:
	public Participant
{
public:
	Player(const char* pname);	// 引数付きコンストラクタ

	// コンストラクタで動的にメモリを確保するので、
	// コピーと代入を禁止する
	Player(const Player& other) = delete;
	Player& operator=(const Player& other) = delete;

	~Player();	// コピーした名前を delete するためのデストラクタ
};