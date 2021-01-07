#include "HandPlayer.h"
#include <iostream>;

// Constructor that calls the hand constructor using the given size
HandPlayer::HandPlayer(int size) : Hand(size) 
{

}

// Get Card method that ask for input and returns a card
Card HandPlayer::GetCard(int Suit, bool FirstPlayer, bool HeartsBroken)
{
	// Checks whether it the first player
	if (FirstPlayer != true) {
		// Sets a bool to false used to guarentee correct input is gotten
		bool CorrectInput = false;
		// Seatches for the suit in the hand
		if (CardSearch(Suit, 14) == false) {
			// If the suit isn't their then the player can select any index
			while (CorrectInput == false) {
				// Asks the player to enter any number
				cout << "Enter a number corresponding to a card: ";
				// Gets the input
				cin >> Option;
				// Checks whether cin is true (An int has been given)
				if (cin) {
					// Checks whether the option given is correct
					if (Option > 0 && Option <= HandSize) {
						// Checks whether its a heart and hearts are broken
						if (HeartsBroken == false && Storage[Option - 1].ReturnSuit() == 0) {
							// Tells the user to break the hearts before playing one at the start of a round
							cout << endl << "Hearts need to be broken before you can start with a heart" << endl;
						}
						else {
							// Breaks the while loop
							CorrectInput = true;
						}
					}
				}
				// Used so that if(Cin) works
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}
		// Card search has found at least one card with that suit
		else {
			do {
				// Tells the user to play a card of that suit
				cout << "You must play a ";
				switch (Suit) {
				case 0:
					cout << "Heart" << endl;
					break;
				case 1:
					cout << "Spade" << endl;
					break;
				case 2:
					cout << "Diamond" << endl;
					break;
				case 3:
					cout << "Club" << endl;
					break;
				case 4:
					// Testing case
					cout << "This shouldn't happen";
					break;
				}
				// Tells the user to enter a number
				cout << "Enter a number corresponding to a card: ";
				cin >> Option;
				// Same cin check as above (Checks for int)
				if (cin) {
					// Checks whether input is a correct index+1
					if (Option > 0 && Option <= HandSize) {
						// Checks that the suit given is correct or if suit doesnt matter statement evaluates true
						if (Storage[Option - 1].ReturnSuit() == Suit || Suit == 4) {
							// Breaks the do while
							CorrectInput = true;
						}
					}
				}
				// Makes sure cin works (Will keep sending couts if not used
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				// Checks whether correct input is true, if it is breaks the Do While loop
			} while (CorrectInput == false);
		}
	}
	// Its first player
	else {
		// Tells the user they have played the 2 of clubs
		cout << "You have the 2 of Clubs so play it first" << endl;
		// Checks the whole hand
		for (int i = 0; i < HandSize; i++) {
			// Finds 2 of clubs
			if (Storage[i].ReturnSuit() == 3 && Storage[i].ReturnVal() == 2) {
				// Increments Option by 1 so matches what a normal player input would give
				Option = i + 1;
				// Returns the card
				return Storage[i];
			}
		}
	}
	// Returns the card
	return Storage[Option - 1];
}
