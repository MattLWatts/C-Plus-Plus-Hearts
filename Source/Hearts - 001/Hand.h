#pragma once
#include "Card.h";
#include "Deck.h";

// Child of the container class
class Hand : public Container{
protected:
	// Array of cards
	Card *Indexs;
	// Array of ints
	int *IndexsPlaceholder;
	// Current Index
	int IndexCounter = 0;
	// Current Index
	int Index = 0;
	// Option selected from hand
	int Option = 0;
public:
	// Hand constructor
	Hand(int Size);
	// Keeps track of hand size (public for testing)
	int HandSize;
	// Populates hand using the deck from one value to the other
	void PopulateHand(Deck NewDeck, int Lower, int Higher);
	// Used to print the hand
	void PrintHand();
	// Searches hand for specific suit, num or both
	bool CardSearch(int Suit, int Num);
	// Selects a card
	Card SelectCard();
	// Appends a card to be moved in the passing phase
	void AppendCard(Card *Cards);
	// Gets a card at a specific index virtual because polymorphed by hand ai and hand player classes
	virtual Card GetCard(int Suit, bool FirstPlayer, bool HeartsBroken);
	// Resize hand method
	void ResizeHand();
	// Shoot the moon check
	bool ShootTheMoonCheck();
};