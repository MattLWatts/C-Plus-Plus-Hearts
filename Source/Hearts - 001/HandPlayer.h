#pragma once
#include "Hand.h"

class HandPlayer : public Hand{
public:
	// Constructor
	HandPlayer(int size);
	// Get Card, which collects input and returns the card
	Card GetCard(int Suit, bool FirstPlayer, bool HeartsBroken);
};