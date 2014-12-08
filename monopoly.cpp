// monopoly.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "player.h"
#include "propertySpace.h"
#include <string>

using namespace std;

propertySpace properties[40];
player players[10];

int freeParkingAmount;
bool win;

/* Initializes all of the properties and the players */
void initialize() {
	win = false;

	/* Initializes and defines each of the properties */
	properties[0].initialize("Go", "corner", 0, 0);
	properties[1].initialize("Mediterranean Avenue", "brown", 60, 2, 10, 30, 90, 160, 250);
	properties[2].initialize("Community Chest", "card", 0, 0);
	properties[3].initialize("Baltic Avenue", "brown", 60, 4, 20, 60, 180, 320, 450);
	properties[4].initialize("Income Tax", "tax", 0, 200);
	properties[5].initialize("Reading Railroad", "railroad", 200, 25);
	properties[6].initialize("Oriental Avenue", "light-blue", 100, 6, 30, 90, 270, 400, 550);
	properties[7].initialize("Chance", "card", 0, 0);
	properties[8].initialize("Vermont Avenue", "light-blue", 100, 6, 30, 90, 270, 400, 550);
	properties[9].initialize("Conneticut Avenue", "light-blue", 100, 8, 40, 100, 300, 450, 600);
	properties[10].initialize("Jail", "corner", 0, 0);
	properties[11].initialize("St. Charles Place", "pink", 140, 10, 50, 150, 450, 625, 750);
	properties[12].initialize("Electric Company", "utility", 150, 10);
	properties[13].initialize("State Avenue", "pink", 140, 10, 50, 150, 450, 625, 750);
	properties[14].initialize("Virginia Avenue", "pink", 160, 12, 60, 180, 500, 700, 900);
	properties[15].initialize("Pennysylvania Railroad", "railroad", 200, 25);
	properties[16].initialize("St. James Place", "orange", 180, 14, 70, 200, 550, 750, 950);
	properties[17].initialize("Community Chest", "card", 0, 0);
	properties[18].initialize("Tennessee Avenue", "orange", 180, 14, 70, 200, 550, 750, 950); 
	properties[19].initialize("New York Avenue", "orange", 200, 16, 80, 220, 600, 800, 1000);
	properties[20].initialize("Free Parking", "corner", 0, 0);
	properties[21].initialize("Kentucky Avenue", "red", 220, 18, 90, 250, 700, 875, 1050);
	properties[22].initialize("Chance", "chance", 0, 0);
	properties[23].initialize("Indiana Avenue", "red", 220, 18, 90, 250, 700, 875, 1050);
	properties[24].initialize("Illinois Avenue", "red", 240, 20, 100, 300, 750, 925, 1100);
	properties[25].initialize("B & O Railroad", "railroad", 200, 25);
	properties[26].initialize("Atlantic Avenue", "yellow", 260, 22, 110, 330, 800, 927, 1150);
	properties[27].initialize("Ventnor Avenue", "yellow", 260, 22, 110, 330, 800, 927, 1150);
	properties[28].initialize("Water Works", "utility", 150, 0);
	properties[29].initialize("Marvin Gardens", "yellow", 280, 24, 120, 360, 850, 1025, 1200);
	properties[30].initialize("Go to Jail", "corner", 0, 0);
	properties[31].initialize("Pacific Avenue", "green", 300, 26, 130, 390, 900, 1100, 1275);
	properties[32].initialize("North Carolina Avenue", "green", 300, 26, 130, 390, 900, 1100, 1275);
	properties[33].initialize("Community Chest", "card", 0, 0);
	properties[34].initialize("Pennsylvania Avenue", "green", 320, 28, 150, 450, 1000, 1200, 1400);
	properties[35].initialize("Short Line", "railroad", 200, 25);
	properties[36].initialize("Chance", "card", 0, 0);
	properties[37].initialize("Park Place", "blue", 350, 25, 175, 500, 1100, 1300, 1500);
	properties[38].initialize("Luxury Tax", "tax", 0, 100);
	properties[39].initialize("Boardwalk", "blue", 400, 50, 200, 600, 1400, 1700, 2000);

	//Sets the variables to be used when defining players and AI difficulty
	int numberOfPlayers;
	int numberOfHumans;
	int aiDifficulty;

	//Prompts the user to set up the game
	cout << "How many players are playing? (This includes both human and AI. Max is 10.)" << endl << "Please enter a number (1-10)." << endl;
	cin >> numberOfPlayers;
	cout << "How many players will be human? Please enter a number (1-10)";
	cin >> numberOfHumans;

	//Asks the user what difficulty he/she wants the AI to be (Functionality to be decided later)
	if(numberOfPlayers - numberOfHumans != 0) {
		cout << "What difficulty would you like the AI to be on? Please enter a number (1-5)." << endl << "Note: this functionality is not built in yet; It is just a placeholder for data;" << endl;
		cin >> aiDifficulty;
	}

	//Declares each of the human players
	for(int i = 0; i < numberOfHumans; i++) {
		string username;
		cout << "Enter the username for Player" << i << "." << endl;
		cin >> username;
		players[i].initialize(username, 0);
	}

	//Declares each of the AI players
	for(int i = numberOfHumans; i < numberOfPlayers; i++) {
		players[i].initialize("Computer " + (i - numberOfHumans + 1), aiDifficulty);
	}
}

//Displays the command help
void promptHelp() {
	cout << "Command        |   Action" << endl;
	cout << "_________________________________________________________________________________________" << endl;
	cout << "help           |   Displays this prompt" << endl;
	cout << "roll dice      |   Rolls the dice to move the player" << endl;
	cout << "buy house      |   Buys a house to put on a porperty" << endl;
	cout << "buy property   |   Buys the property the player is currently on" << endl;
	cout << "sell house     |   Sells a certain amount of houses on a selected property" << endl;
	cout << "sell property  |   Sells a selected property (and all the houses on it if there are any)" << endl;
	cout << "trade          |   Initiates a trade with a selected player" << endl;
	cout << "who owns this  |   Returns the owner of the current property." << endl;

}

//Promps the player for an action
void prompt(player current, propertySpace property) {
	//If it's a human player's turn
	if(current.difficulty == 0) {
		string answer;   //Variable to store their answer in
		int dice[3];     //The results from the die roll

		cout << "What would you like to do?" << endl;
		cin >> answer;

		if(answer == "help") {
			promptHelp();
		}
		else if(answer == "roll dice") {
			//If the user is not in jail
			if(current.ifInJail() == false) {
				//The player moves
				current.move(dice[2]);
			}
			else {
				//Rolls the dice and stores it in an array
				//dice = current.rollDice();

				//If the player has NOT been in jail for three turns
				if(current.jailTurns != 3) {
					if(dice[0] == dice[1]) { //If the user rolls doubles
						current.getOutOfJail(); //Get the user out of jail
					}
					else {
						current.jailTurns++; //Add another one to the amount of turns the user has been in jail
						current.endTurn();
					}
				}
				//If the player has been in jail for three turns
				else {
					if(dice[0] == dice[1]) { //If the user rolls doubles
						current.getOutOfJail(); //Gets the user out of jail
					}
					else { //If the user does NOT roll doubles
						current.setCash(current.getCash() - 50); //Make the player pay the mandatory $50 fee to get out of jail 
						current.getOutOfJail(); //Gets the user out of jail
					}
					current.jailTurns = 0; //Sets the amount of turns the user has been in jali to 0
				}	
			}
		}
		else if(answer == "buy house") {
			cout << "How many houses would you like?" << endl;
			int numberOfHouses;
			cin >> numberOfHouses;

			if(cin) {
				//Function to be built out
				property.buyHouse(numberOfHouses, current);
			}
			else {
				cout << "Please enter a nuber, 1-5";
				prompt(current, property);
			}

			prompt(current, property);
		}
		else if(answer == "buy property") {
			if(property.getOwner() == "No Owner") {
				property.setOwner(current);
			}
			else {
				cout << "This property is already owned by " << property.getOwner() << "." << endl;
				cout << "Perhaps consider a trade." << endl;
			}
		}
		else if(answer == "who owns this") {
			cout << property.getOwner();
			prompt(current, property);
		}
		else {
			cout << "I was unable to figure out what the hell you're trying to say." << endl;
			prompt(current, property);
		}
	}

	return;
}

int checkProperty(player current, int id) 
{
	propertySpace property = properties[id];
	string owner = properties[id].getOwner();
	int price = properties[id].getPrice();
	int rent = properties[id].getRent();

	if(owner != "No Owner") {
		cout << "This property is available." << endl << "The price is " << price << "." << endl;
		cout << "Would you like to buy it? (y/n)" << endl;
		
		string response = "";
		cin >> response;

		if(response == "y" || response == "Y") {
			property.setOwner(current);
			return 0;
		}
		else if(response == "n" || response == "N") {
			return 0;
		}
		else {
			cout << "I do not understand what you are saying, so I am going to assume you don't want to buy it." << endl;
			return 0;
		}
	}
}

void play() {
	promptHelp();

	while(!win) {
		for each(player current in players) {
			cout << "It is now " << current.username << "'s turn." << endl;
			prompt(current, properties[current.currentProperty()]);
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	initialize();
	cout << "Game initialized." << endl;
	play();

	return 0;
}