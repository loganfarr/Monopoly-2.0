#include "stdafx.h"
#include "propertySpace.h"
#include <string>

propertySpace::propertySpace() {
	houses = 0;
}

propertySpace::propertySpace(int pid, std::string ptitle, std::string pcolor, int pprice, int baseRent)
{
	id = pid;
	title = ptitle;
	color = pcolor;
	price = pprice;
	rent[0] = baseRent;
	houses = 0;
}

propertySpace::propertySpace(int pid, std::string ptitle, std::string pcolor, int pprice, int baseRent, int oneHouse, int twoHouse, int threeHouse, int fourHouse, int hotel) {
	id = pid;
	title = ptitle;
	color = pcolor;
	price = pprice;
	rent[0] = baseRent;
	rent[1] = oneHouse;
	rent[2] = twoHouse;
	rent[3] = threeHouse;
	rent[4] = fourHouse;
	rent[5] = hotel;
	houses = 0;
}

void propertySpace::initialize(std::string ptitle, std::string pcolor, int pprice, int baseRent) {
	title = ptitle;
	color = pcolor;
	price = pprice;
	rent[0] = baseRent;
	houses = 0;
	owner = "";
	mortgaged = false;
}

void propertySpace::initialize(std::string ptitle, std::string pcolor, int pprice, int baseRent, int oneHouse, int twoHouses, int threeHouses, int fourHouses, int hotel) {
	title = ptitle;
	color = pcolor;
	price = pprice;
	rent[0] = baseRent;
	rent[1] = oneHouse;
	rent[2] = twoHouses;
	rent[3] = threeHouses;
	rent[4] = fourHouses;
	rent[5] = hotel;
	houses = 0;
	owner = "";
	mortgaged = false;
}


void propertySpace::checkProperty(propertySpace properties[], int id) {
	
}

std::string propertySpace::getOwner() {
	if(owner != null) {
		return owner;
	}
	else {
		return "No Owner";
	}
}

void propertySpace::setOwner(player current) {
	int playerCash = current.getCash();
	if(playerCash < price) {
		cout << "You don't have enough money to purchase this property.";
		return; 
	}
	else {
		current.setCash(playerCash - price);
		this.setOwner(current.username);
	}
}

propertySpace::~propertySpace(void) { }