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

int* player::rollDice(int dice[]) {
	int die1 = rand() % 6 + 1;
	int die2 = rand() % 6 + 1;

	int die[3];
	die[0] = die1;
	die[1] = die2;
	die[2] = die1 + die2;

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

	return die;
}

int player::move(int dice) {
	if(currentPosition + dice >= 40) {
		currentPosition = currentPosition + dice - 40;
	}
	else {
		currentPosition += dice;
	}
	
	return currentPosition;
}

int player::currentProperty() {
	return currentPosition;
}

void player::endTurn() {
		
}

player::~player(void) {}