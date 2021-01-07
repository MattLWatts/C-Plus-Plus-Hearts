#pragma once
#include <iostream>;
#include "Hand.h";
#include "Table.h";

using namespace std;

class GameManager {
public:
	// Constructor
	GameManager();
	// Pass cards method - takes memory address of the hands
	void PassCards(Hand &Hand1, Hand &Hand2, Hand &Hand3, Hand &Hand4);
	// Play cards method - takes memory address of the hands
	void PlayHand(Hand &Hand1, Hand &Hand2, Hand &Hand3, Hand &Hand4, Table &Table1, bool IsFirst);
	// Print scores method
	void PrintScores();
	// Gets and Set methods used for highscore files
	int GetScore(int Player);
	void SetScore(int Player,int Score);
	int GetDirection();
	void SetDirection(int DesiredDirection);
private:
	// Direction used to keep track of which way the hand should be passed
	int Direction = 0;
	// The starting player when playing cards
	int Order = 1;
	// Suit in the trick
	int SuitInUse = 0;
	// Score variables
	int Player1Score;
	int Player2Score;
	int Player3Score;
	int Player4Score;
	// Heart broken variable
	bool HeartsBroken = false;
};