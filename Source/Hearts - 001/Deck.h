#pragma once
#include "Card.h";
#include <vector>;
#include "Container.h";

using namespace std;

// Inherits from Container class
class Deck : public Container{
public:
	// Constructor
	Deck();
	// Shuffle method
	void Shuffle();
	// Fills the deck
	void FillDeck();
};	