#include "stdafx.h"
#include "propertySpace.h"
#include "player.h"
#include <iostream>
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
	owner = "";
}

propertySpace::propertySpace(int pid, std::string ptitle, std::string pcolor, int pprice, int baseRent, int oneHouse, int twoHouse, int threeHouse, int fourHouse, int hotel) 
{
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
	owner = "";
}

void propertySpace::initialize(std::string ptitle, std::string pcolor, int pprice, int baseRent) 
{
	title = ptitle;
	color = pcolor;
	price = pprice;
	rent[0] = baseRent;
	houses = 0;
	owner = "";
	mortgaged = false;
}

void propertySpace::initialize(std::string ptitle, std::string pcolor, int pprice, int baseRent, int oneHouse, int twoHouses, int threeHouses, int fourHouses, int hotel) 
{
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


void propertySpace::checkProperty(int id) 
{
	if(owner == "") {
		std::cout << "No one currently owns this property (" << title << ")." << std::endl;
		std::cout << "Purchasing price: " << price << std::endl;
		std::cout << "Would you like to purchase it? (y/n)" << std::endl;
		std::string answer;
		std::cin >> answer;
		if(answer == "y") {
			
		}
	}
}

void propertySpace::setOwner(player current) 
{
	int playerCash = current.getCash();
	if(playerCash < price) {
		std::cout << "You don't have enough money to purchase this property.";
		return; 
	}
	else {
		current.setCash(playerCash - price);
		owner = current.username;
		std::cout << "The new owner of this property is " << this->getOwner() << std::endl;
	}
}

void propertySpace::buyHouse(int numberOfHouses, player current) 
{
	if(houses == 5) {
		std::cout << "You have the maximum amount of houses on this property." << std::endl;
	}
	else if(houses + numberOfHouses > 5) {
		std::cout << "You already have " << houses << " number of houses on the property. You cannot have more than a total of 5 houses on the property." << std::endl;
	}
	else {
		int cash = current.getCash();
		int housePrice = price / 2;

		if(cash < housePrice * numberOfHouses) {
			std::cout << "You do not have enough money to purchase that many houses." << std::endl;
		}
		else {
			current.setCash(cash - numberOfHouses * housePrice);
			std::cout << current.username << " now has $" << current.getCash() << std::endl;
			houses += numberOfHouses;
		}

	}
}

propertySpace::~propertySpace(void) { }