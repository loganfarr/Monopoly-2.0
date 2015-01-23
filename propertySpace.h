#pragma once
#include "player.h"
#include <string>

class propertySpace
{
private:
	int id;
	std::string title;
	std::string color;
	int price;
	int rent[6];
	int houses;
	std::string owner;
	bool mortgaged;

public:
	propertySpace();
	propertySpace(int id, std::string ptitle, std::string pcolor, int pprice, int baseRent);
	propertySpace(int id, std::string ptitle, std::string pcolor, int pprice, int baseRent, int oneHouse, int twoHouses, int threeHouses, int fourHouses, int hotel);
	void initialize(std::string ptitle, std::string pcolor, int pprice, int baseRent);
	void initialize(std::string ptitle, std::string pcolor, int pprice, int baseRent, int oneHouse, int twoHouses, int threeHouses, int fourHouses, int hotel);
	void setOwner(player owner);
	void checkProperty(int id);
	void buyHouse(int numberOfHouses, player current);
	~propertySpace(void);

	int getPrice(void) 
	{
		return price;
	}

	std::string getOwner(void) 
	{
		return owner;
	}

	int getHouses(void)
	{
		return houses;
	}

	int getRent(void) 
	{
		return rent[houses];
	}

	std::string getTitle(void) 
	{
		return title;
	}
};