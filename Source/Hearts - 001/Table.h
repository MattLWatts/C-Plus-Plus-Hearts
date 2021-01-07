#pragma once
#include "Deck.h";

class Table : public Container{
public:
	// Constructor
	Table();
	// Gets the score on the table
	int GetTableScore();
	// Gets the highest card and returns the players number
	int GetHighestCard(int Suit);
	// Sets the value of a card
	void SetValue(Card NewCard, int PlayerNum);
	// Outputs the table
	void Output();
private:
	// Creates a pointer to the first item in an array of bools to check which players have played a card
	bool *CardsOnTable;
};