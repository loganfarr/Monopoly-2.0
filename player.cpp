#include "stdafx.h"
#include "player.h"
#include "propertySpace.h"
#include <iostream>

/**
	Constructor for the "Player" class.
	Parameters:
		name - username for the player
		AIDifficulty - 0 for human, 1 for AI (Difficulty to be calculated in later)
*/
player::player() {
	cash = 1500;
	currentPosition = 0;
}

player::player(std::string name, int AI) {
	username = name;
	cash = 1500;
	difficulty = AI;
	currentPosition = 0;
	inJail = false;
}

void player::initialize(std::string name, int AI) {
	username = name;
	cash = 1500;
	difficulty = AI;
	currentPosition = 0;
	inJail = false;
}

void player::setCash(int setAmount) {
	cash = setAmount;
}

int player::getCash() {
	return cash;
}

void player::putInJail() {
	inJail = true;
}

void player::getOutOfJail() {
	inJail = false;
	std::cout << "You are now out of jail." << std::endl;
}

bool ifInJail() {
	return inJail;
}

int player::rollDice() {
	int die1 = rand() % 6 + 1;
	int die2 = rand() % 6 + 1;

	int die[3];
	die[1] = die1;
	die[2] = die2;
	die[3] = die1 + die2;

	int total = die1 + die2;

	//std::cout << "Dice rolled a " << total << std::endl;

	if(!inJail) {
		currentPosition += total;
	}
	if(inJail && (die1 == die2)) {
		currentPosition += total;
	}
	else {
		endTurn();	
	}

	return die[];
}

int player::move() {
	int dice = rollDice();

	if(currentPosition + dice[3] >= 40) {
		currentPosition = currentPosition + dice[3] - 40;
	}
	else {
		currentPosition += dice[3];
	}
	
	return currentPosition;
}

int move(int dice) {
	
}

int player::currentProperty() {
	return currentPosition;
}

void player::endTurn() {
		
}

player::~player(void) {}