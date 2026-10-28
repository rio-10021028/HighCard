#pragma once

class Player
{
private:
	const char* name;
	int number;

public:
	Player(const char* pname);
	void hit();
	int getNumber();
	void showNumber();

	void showName();	// name を表示
};