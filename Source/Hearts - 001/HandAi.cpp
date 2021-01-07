#include "HandAi.h"
#include <iostream>;

// Constructor calls hand with the size
HandAi::HandAi(int size) : Hand(size)
{

}

// Returns a card at the given index
Card HandAi::GetCard(int Suit, bool FirstPlayer, bool HeartsBroken)
{
	// Checks if it isnt the first player
	if (FirstPlayer != true) {
		// Sets a bool to keep the do loop running to false
		bool CorrectInput = false;
		// Searches for the desired suit
		if (CardSearch(Suit, 14) == false) {
			do {
				// If the suit isn't there then the Ai can select any card
				// Random from 0 to < HandSize
				Option = rand() % HandSize;
				// Checks whether its a heart. If it is checks whether hearts are broken yet
				if (Storage[Option].ReturnSuit() == 0 && HeartsBroken == false) {

				}
				else {
					// If it isnt a heart, or it is and hearts are broken then it incerements option so that its inline with a players input
					Option += 1;
					// Breaks the do while loop
					CorrectInput = true;
				}
			// The check at the end of the Do loop
			} while (CorrectInput == false);
		}
		// If the search does find a card of that suit
		else {
			// Runs until a correct input
			do {
				// Gets a value from 0 to < HandSize
				Option = rand() % HandSize;
				// Checks whether the input is the desited suit
				if (Storage[Option].ReturnSuit() == Suit) {
					// Increments the option
					Option += 1;
					// Sets the current input to true
					CorrectInput = true;
				}
				// Checks whether correct input is true so that it can break the Do While loop
			} while (CorrectInput == false);
		}
	}
	// This Ai has the 2 of clubs
	else {
		// Searches entire hand
		for (int i = 0; i < HandSize; i++) {
			// Checks for the 2 of clubs
			if (Storage[i].ReturnSuit() == 3 && Storage[i].ReturnVal() == 2) {
				// Increments again by 1 to give same input as player
				Option = i + 1;
				// Returns the card at the actual index
				return Storage[i];
			}
		}
	}
	// Returns card at the actual index
	return Storage[Option - 1];
}
