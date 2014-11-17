#pragma once
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
	void setOwner(std::string owner);
	void checkProperty(int id);
	std::string getOwner();
	~propertySpace(void);
};