#include "Card.h"
#include <iostream>;

using namespace std;

// Constuctor for card
Card::Card(int NumInput, int SuitInput, bool Face)
{
	// Sets it to an enum casted value of given int and suit value
	CardNum = (Num)NumInput;
	CardSuit = (Suit)SuitInput;
	// Whether the card can or cant be seen
	FaceUp = Face;
}

// Flips the card.
void Card::FlipCard()
{
	FaceUp != FaceUp;
}

// Outputs the number to the screen using the Number stored for each card
void Card::GetNum()
{
	// Casts the enum of Num to an int to be used in the switch
	switch (static_cast<int>(CardNum)) {
	case 1: cout << "Ace"; break;
	case 11: cout << "Jack"; break;
	case 12: cout << "Queen"; break;
	case 13: cout << "King"; break;
	// For all numbers it does the same cast to output the number
	default: cout << static_cast<int>(CardNum); break;
	}
}

// Outputs the suit to the screen using the Suit stored for each card
void Card::GetSuit()
{
	// Casts the enum to a number for the output in the switch
	switch (static_cast<int>(CardSuit)) {
	case 0: cout << " of Hearts "; break;
	case 1: cout << " of Spades "; break;
	case 2: cout << " of Diamonds "; break;
	case 3: cout << " of Clubs "; break;
	}
}

// Gets the point value for each card. Will be used for scoring
int Card::GetValue()
{
	if (CardSuit == Suit::Heart) {
		return (1);
	}
	else if (CardSuit == Suit::Spade && CardNum == Num::Queen) {
		return(13);
	}
	else {
		return (0);
	}
}

// Returns the value for the number
int Card::ReturnVal()
{
	// Returns it as an int
	return static_cast<int>(CardNum);
}

// Returns the value for the suit
int Card::ReturnSuit()
{
	// Returns it as an int
	return static_cast<int>(CardSuit);
}
