#pragma once
#include <string>

class player
{
private:
	int cash;
	bool inJail;
	int numberOfPropertiesOwned;
	std::string propertiesOwned[36];
	int difficulty;
	int netWealth;
	int currentPosition;

public:
	player();
	player(std::string name, int AI);
	void initialize(std::string name, int AI);
	~player(void);
	std::string username;
	void prompt();
	int rollDice(void);
	int move();
	void setCash(int setAmount);
	int getCash(void);
	void putInJail(void);
	void getOutOfJail(void);
	bool ifInJail();
	int approxWealth(void);
	int currentProperty();
	bool gutInstinct();
	int calculateNetWealth();
	void endTurn();
	int jailTurns;
};