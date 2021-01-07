#pragma once
#include "Card.h";
#include <vector>;

using namespace std;

class Container {
protected:
	// Storage card vector used by all child classes
	vector<Card> Storage;
public:
	// Constructor
	Container(int Size);
	// Outputs the container
	virtual void Output();
	// Gets and returns a card
	Card GetCard(int Index);
};