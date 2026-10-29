#pragma once

class Player
{
private:
	const char* name;
	int number;

public:
	Player(const char* pname);
	void hit();
	int getNumber() const;
	void showNumber() const;

	void showName() const;	// name を表示
};