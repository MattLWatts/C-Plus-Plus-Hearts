#include "Table.h"
#include <iostream>;

using namespace std;

// Uses container constructor with size 4
Table::Table(): Container(4)
{
	// Creates an array of bools with size 4, to keep track of who has played
	CardsOnTable = new bool[4];
	// Sets the table values to 4 blank ones
	Storage.push_back(Card());
	Storage.push_back(Card());
	Storage.push_back(Card());
	Storage.push_back(Card());
}

// Sets the value to given card at the players position on the table
void Table::SetValue(Card NewCard, int PlayerNum)
{
	// Sets the position on the table to the given card
	Storage[PlayerNum-1] = NewCard;
	// Sets the value of whether the card has been played to true at the players position
	CardsOnTable[PlayerNum - 1] = true;
}

void Table::Output()
{
	// Prints the table
	for (int i = 0; i < 4; i++) {
		// Checks whether the player has played yet
		if (CardsOnTable[i] == true) {
			// Prints when the player has played a card
			cout << "Player " << (i + 1) << " Plays the: ";
			// Prints the number and suit
			Storage[i].GetNum();
			Storage[i].GetSuit();
			// Ends the line
			cout << endl;
		}
	}
	cout << endl;
}

// Gets the tables total score
int Table::GetTableScore()
{
	// Initialises it as 0
	int TotalHandScore = 0;
	// Goes through the table
	for (int i = 0; i < 4; i++) {
		// Gets the score of each position and adds it to the total
		TotalHandScore += Storage[i].GetValue();
		// Sets the bool array to false for the next round
		CardsOnTable[i] = false;
	}
	// Returns the tables total score
	return TotalHandScore;
}

// Checks which player won the round with the highest card
int Table::GetHighestCard(int Suit)
{
	// Sets the highest num to 0
	int CurrentHighestNum = 0;
	// Sets the current player to 1
	int CurrentHighestPlayer = 1;
	// Searches the table
	for (int i = 0; i < 4; i++) {
		// Checks if the card is in the suit of the round
		if (Storage[i].ReturnSuit() == Suit) {
			// Checks if the cards value is higher than the current highest
			if (Storage[i].ReturnVal() > CurrentHighestNum) {
				// Sets it equal to the highest played number
				CurrentHighestNum = Storage[i].ReturnVal();
				// Sets the current highest player to the one with the highest card
				CurrentHighestPlayer = i + 1;
			}
		}
	}
	// Returns the current highest players number
	return CurrentHighestPlayer;
}