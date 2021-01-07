#pragma once

class Card {
public:
	// Constuctor for the card class
	Card(int NumInput, int SuitInput, bool Face);
	Card() {};
	// Basic gets and sets
	void FlipCard();
	void GetNum();
	void GetSuit();
	int GetValue();
	int ReturnVal();
	int ReturnSuit();
private:
	// Strongly typed enum for suit
	enum class Suit {
		Heart = 0,
		Spade,
		Diamond,
		Club
	};
	// Strongly typed enum for num
	enum class Num {
		Ace = 1,
		Two,
		Three,
		Four,
		Five,
		Six,
		Seven,
		Eight,
		Nine,
		Ten,
		Jack,
		Queen,
		King
	};
	// Properties of face, number and suit
	Num CardNum;
	Suit CardSuit;
	bool FaceUp;
};