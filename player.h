#pragma once
#include <string>
#include <iostream>

class player
{
private:
	int cash;
	bool inJail;
	int numberOfPropertiesOwned;
	std::string propertiesOwned[36];
	int netWealth;
	int currentPosition;

public:
	player();
	player(std::string name, int AI);
	void initialize(std::string name, int AI);
	~player(void);
	std::string username;
	void prompt();
	int* rollDice(int dice[]);
	int move(int dice);
	int approxWealth(void);
	int currentProperty(void);
	bool gutInstinct(void);
	int calculateNetWealth(void);
	void endTurn(void);
	int jailTurns;
	int difficulty;

	void setCash(int setAmount)
	{
		cash = setAmount;
	}

	int getCash(void)
	{
		return cash;
	}

	void putInJail(void)
	{
		inJail = true;
	}

	bool ifInJail(void)
	{
		return inJail;
	}

	void getOutOfJail(void)
	{
		inJail = false;
		std::cout << "You are now out of jail." << std::endl;
	}
};