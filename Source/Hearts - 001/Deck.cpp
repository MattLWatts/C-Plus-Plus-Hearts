#include "Deck.h";
#include <cstdlib>;
#include <iostream>;

using namespace std;

// Calls the container constructor with size of 52
Deck::Deck() : Container(52)
{

}

// Fills the deck
void Deck::FillDeck()
{
	// Creates the suit values for the cards (0-4)
	for (int i = 0; i < 4; i++) {
		// Creates the number values for the cards (1-13)
		for (int y = 1; y < 14; y++) {
			// Pushes a new card onto the vector
			Storage.push_back(Card(y, i, true));
		}
	}
}

// Shuffles the Deck
void Deck::Shuffle()
{
	// Creates a random index of a first card
	int RandomVal = rand() % 52;
	// Creates another random index of another card
	int RandomMove = rand() % 52;
	// Creates a placeholder used to store one of the indexs
	Card Placeholder;
	// Gives the placeholder the value of a card at the random val index
	Placeholder = Storage[RandomVal];
	// Swaps the cards
	Storage[RandomVal] = Storage[RandomMove];
	// Gives the other index the value of the placeholder card
	Storage[RandomMove] = Placeholder;
}
