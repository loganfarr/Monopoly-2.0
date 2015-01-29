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

int* player::rollDice() {
	int * die = new int[3];

	int die1 = rand() % 6 + 1;
	int die2 = rand() % 6 + 1;

	die[0] = die1;
	die[1] = die2;
	die[2] = die1 + die2;

	return die;
}

int player::move(int * dice) {
	//If the user is not in jail
	if(this->ifInJail() == false) {
		//The player moves
		if(currentPosition + dice[3] >= 40) {
			this->currentPosition = currentPosition + dice[3] - 40;
		}
		else {
			this->currentPosition += dice[3];
		}
		
		return currentPosition;
	}
	else {
		//If the player has NOT been in jail for three turns
		if(this->jailTurns != 3) {
			if(dice[0] == dice[1]) { //If the user rolls doubles
				this->getOutOfJail(); //Get the user out of jail
			}
			else {
				this->jailTurns++; //Add another one to the amount of turns the user has been in jail
			}
		}
		//If the player has been in jail for three turns
		else {
			if(dice[0] != dice[1]) { //If the user does NOT roll doubles
				this->setCash(this->getCash() - 50); //Make the player pay the mandatory $50 fee to get out of jail 
			}

			this->getOutOfJail(); //Gets the user out of jail
			this->jailTurns = 0; //Sets the amount of turns the user has been in jali to 0
		}	
	}

	return NULL;
}

int player::currentProperty() {
	return currentPosition;
}

void player::endTurn() {
		
}

player::~player(void) {}