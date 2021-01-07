#include "Hand.h"
#include "GameManager.h"
#include <iostream>;

using namespace std;

// Calls the container and sets equal to the given size
Hand::Hand(int Size) : Container(Size)
{
	// Sets the hand size to that size
	HandSize = Size;
	// Creates an array of 3 cards which will store the cards to pass
	Indexs = new Card[3];
	// An array of positions to replace with the cards passed to it
	IndexsPlaceholder = new int[3];
}

// Populates the hand with part of a deck
void Hand::PopulateHand(Deck NewDeck, int Lower, int Higher)
{
	// For statement that goes from the lower bound given to the higher
	for (Lower; Lower < Higher; Lower++) {
		// Pushes the card on to the vector
		Storage.push_back(NewDeck.GetCard(Lower));
	}
}

// Outputs the hand
void Hand::PrintHand()
{
	// Goes through the whole hand
	for (int i = 0; i < HandSize; i++) {
		// Outputs the number corresponding to each card 1 higher than the index in the array
		cout << i + 1;
		// Puts a parenthesis after the number for ease of reading
		cout << ") ";
		// Outputs the cards information
		Storage[i].GetNum();
		Storage[i].GetSuit();
		// Ends the line
		cout << endl;
	}
	// Puts a line break between the list of cards and whatevers next
	cout << endl;
}

// Selects a card to pass to another player
Card Hand::SelectCard()
{
	// Creates a variable used to store the current input
	Card Input;
	// Creates a variable to check whether the same input has been given
	bool IsAlreadyIn = true;
	// Keeps running the same code till different values have been entered
	while (IsAlreadyIn == true) {
		// Gets the input from the user
		Input = GetCard(4,false,true);
		// Checks if that input list already has the input given above
		if (Indexs[0].ReturnSuit() != Input.ReturnSuit() || Indexs[0].ReturnVal() != Input.ReturnVal()) {
			if (Indexs[1].ReturnSuit() != Input.ReturnSuit() || Indexs[1].ReturnVal() != Input.ReturnVal()){
				if (Indexs[2].ReturnSuit() != Input.ReturnSuit() || Indexs[2].ReturnVal() != Input.ReturnVal()) {
					// If the card hasnt been chosen yet then it breaks the while loop
					IsAlreadyIn = false;
				}
			}
		}
	}
	// Adds the input to the Index array
	Indexs[IndexCounter] = Input;
	// Adds the position to the index placeholder array
	IndexsPlaceholder[IndexCounter] = Option - 1;
	// Incements the index counter by 1
	IndexCounter += 1;
	// Checks if is at a index of 2 and sets it to 0 incase it needs to be ran again
	if (IndexCounter > 2) {
		IndexCounter = 0;
	}
	// Returns the card at the index given from the input
	return Input;
}

// Appends 3 card to the hand
void Hand::AppendCard(Card *Cards)
{
	// Appends 3 cards from another hand to this hand at the location stored in the Indexs array
	for (int i = 0; i < 3; i++) {
		Storage[IndexsPlaceholder[i]] = Cards[i];
	}
}

// If the number inputted is 14 then its a number only search
// If the suit is 4 then its a search for a specfic number
// If neither are 4 or 14 then its a specific card search
bool Hand::CardSearch(int Suit = 4, int Num = 14)
{
	// Checks whole hand
	for (int i = 0; i < HandSize; i++) {
		// Check for specific number
		if (Suit == 4 && Num != 14) {
			// Checks if number is there
			if (Storage[i].ReturnVal() == Num) {
				// Returns true if it is
				return true;
			}
		}
		// Checks for specific suit
		else if (Num == 14 && Suit != 4) {
			// Checks if specfic suit is there
			if (Storage[i].ReturnSuit() == Suit) {
				// Returns true if it is
				return true;
			}
		}
		// Check for specific card (Number & Suit)
		else if (Storage[i].ReturnSuit() == Suit && Storage[i].ReturnVal() == Num) {
			// Returns true id specific card is there
			return true;
		}
	}
	// If the search was unsuccessful then returns false
	return false;
}

// Deafult get card (Will be overwritten in hand Ai and Player classes
Card Hand::GetCard(int Suit, bool FirstPlayer, bool HeartsBroken)
{
	return Card();
}

// Resizes the hand
void Hand::ResizeHand()
{
	// Checks if the Index isn't at the end of the hand
	if (Option != (HandSize)) {
		// Takes last value and puts it at the position the player played from
		Storage[Option - 1] = Storage[HandSize - 1];
	}
	// Decreases the hand size by 1
	HandSize -= 1;
	// Resizes the vector
	Storage.resize(HandSize);
	Storage.shrink_to_fit();
}

// Checks for Shoot the moon
bool Hand::ShootTheMoonCheck()
{
	// Current total initialised to 0
	int Total = 0;
	// Checks whole hand
	for (int i = 0; i < HandSize; i++) {
		// Increments by the score of each card
		Total += Storage[i].GetValue();
	}
	// If the total is 26 it returns true
	if (Total == 26) {
		return true;
	}
	// Else it returns false
	return false;
}
