#pragma once
#include "Hand.h";

class HandAi : public Hand {
public:
	// Constructor
	HandAi(int size);
	// Get Card, which collects input and returns the card
	Card GetCard(int Suit, bool FirstPlayer, bool HeartsBroken);
};