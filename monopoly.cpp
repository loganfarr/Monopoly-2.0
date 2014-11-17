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

void initialize() {
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

	int numberOfPlayers;
	int numberOfHumans;
	int aiDifficulty;

	cout << "How many players are playing? (This includes both human and AI. Max is 10.)" << endl << "Please enter a number (1-10)." << endl;
	cin >> numberOfPlayers;
	cout << "How many players will be human? Please enter a number (1-10)";
	cin >> numberOfHumans;

	if(numberOfPlayers - numberOfHumans != 0) {
		cout << "What difficulty would you like the AI to be on? Please enter a number (1-5)." << endl << "Note: this functionality is not built in yet; It is just a placeholder for data;" << endl;
		cin >> aiDifficulty;
	}

	for(int i = 0; i < numberOfHumans; i++) {
		string username;
		cout << "Enter the username for Player" << i << "." << endl;
		cin >> username;
		players[i].initialize(username, 0);
	}

	for(int i = numberOfHumans; i < numberOfPlayers; i++) {
		players[i].initialize("Computer " + (i - numberOfHumans + 1), aiDifficulty);
	}
}

void startGame() {

}

int _tmain(int argc, _TCHAR* argv[])
{
	initialize();
	cout << "Game initialized." << endl;
	startGame();

	return 0;
}