#include "GameManager.h"

GameManager::GameManager()
{
	// Sets all the scores to 0
	Player1Score = 0;
	Player2Score = 0;
	Player3Score = 0;
	Player4Score = 0;
}

// Takes the reference to the hands
void GameManager::PassCards(Hand &Hand1, Hand &Hand2, Hand &Hand3, Hand &Hand4)
{
	// Creates 4 temp pointers to arrays of card objects;
	Card *TempArray1, *TempArray2, *TempArray3, *TempArray4;
	TempArray1 = new Card[3];
	TempArray2 = new Card[3];
	TempArray3 = new Card[3];
	TempArray4 = new Card[3];

	// Gets 3 inputs from each player
	for (int i = 0; i < 3; i++) {
		// Selects the cards which gets the input from the players and put the cards in the temp array
		TempArray1[i] = Hand1.SelectCard();
		TempArray2[i] = Hand2.SelectCard();
		TempArray3[i] = Hand3.SelectCard();
		TempArray4[i] = Hand4.SelectCard();
	}

	//Direction 0 = Left, 1 = Right, 2 = Forwards, 3 = No Pass
	if (Direction == 0) {
		// Moves the cards between players in the order 1 > 2 > 3 > 4
		Hand1.AppendCard(TempArray4);
		Hand2.AppendCard(TempArray1);
		Hand3.AppendCard(TempArray2);
		Hand4.AppendCard(TempArray3);
	}
	else if (Direction = 1) {
		// Moves the cards between players in the order 1 > 4 > 3 > 2
		Hand1.AppendCard(TempArray2);
		Hand2.AppendCard(TempArray3);
		Hand3.AppendCard(TempArray4);
		Hand4.AppendCard(TempArray1);
	}
	else if (Direction = 2) {
		// Moves the cards between players in the order 1 > 3 , 2 > 4
		Hand1.AppendCard(TempArray3);
		Hand2.AppendCard(TempArray4);
		Hand3.AppendCard(TempArray1);
		Hand4.AppendCard(TempArray2);
	}
	// Increments the Direction for the next passing
	Direction += 1;
	if (Direction >= 4) {
		Direction = 0;
	}
	// Checks for shoot the moon for each player
	if (Hand1.ShootTheMoonCheck() == true) {
		Player2Score += 26;
		Player3Score += 26;
		Player4Score += 26;
	}
	else if (Hand2.ShootTheMoonCheck() == true) {
		Player1Score += 26;
		Player3Score += 26;
		Player4Score += 26;
	}
	else if (Hand3.ShootTheMoonCheck() == true) {
		Player2Score += 26;
		Player1Score += 26;
		Player4Score += 26;
	}
	else if (Hand4.ShootTheMoonCheck() == true) {
		Player2Score += 26;
		Player3Score += 26;
		Player1Score += 26;
	}

	// Deletes the temp arrays
	delete  TempArray1;
	delete  TempArray2;
	delete  TempArray3;
	delete  TempArray4;
}

// Method for playing hands takes references to the hands and the table
void GameManager::PlayHand(Hand &Hand1, Hand &Hand2, Hand &Hand3, Hand &Hand4,Table &Table1, bool IsFirst)
{

	if (IsFirst == true) {
		// Looks for 2 of clubs for every card
		if (Hand1.CardSearch(3, 2)) {
			Order = 1;
		}
		else if (Hand2.CardSearch(3, 2)) {
			Order = 2;
		}
		else if (Hand3.CardSearch(3, 2)) {
			Order = 3;
		}
		else if (Hand4.CardSearch(3, 2)) {
			Order = 4;
		}
		// Sets first suit to clubs
		SuitInUse = 3;
	}

	// Order 1 = Hand1 First, 2 = Hand2 First, 3 = Hand3 First, 3 = Hand4 First
	if (Order == 1) {
		// Checks whether its the first round
		if (IsFirst == true) {
			// Sets table to 2 of clubs
			Table1.SetValue(Hand1.GetCard(SuitInUse,true, HeartsBroken), 1);
		}
		else {
			// If it isnt the first round then the card selected will become the suit for that round
			Card Choise = Hand1.GetCard(4, false, HeartsBroken);
			// Sets suit to chosen suit
			SuitInUse = Choise.ReturnSuit();
			// Sets position 1 on the table to the selected card
			Table1.SetValue(Choise, 1);
		}
		// Gets the choice of hand from the other players and set them on the table in the correct position
		Table1.SetValue(Hand2.GetCard(SuitInUse, false, true), 2);
		Table1.SetValue(Hand3.GetCard(SuitInUse, false, true), 3);
		Table1.SetValue(Hand4.GetCard(SuitInUse, false, true), 4);
	}
	if (Order == 2) {
		// Checks whether its the first round
		if (IsFirst == true) {
			// Sets table to 2 of clubs
			Table1.SetValue(Hand2.GetCard(SuitInUse, true, HeartsBroken), 2);
		}
		else {
			// If it isnt the first round then the card selected will become the suit for that round
			Card Choise = Hand2.GetCard(4, false, HeartsBroken);
			// Sets suit to chosen suit
			SuitInUse = Choise.ReturnSuit();
			// Sets position 2 on the table to the selected card
			Table1.SetValue(Choise, 2);
		}
		// Gets the choice of hand from the other players and set them on the table in the correct position
		Table1.SetValue(Hand3.GetCard(SuitInUse, false, true), 3);
		Table1.SetValue(Hand4.GetCard(SuitInUse, false, true), 4);
		Table1.Output();
		Table1.SetValue(Hand1.GetCard(SuitInUse, false, true), 1);
	}
	if (Order == 3) {
		// Checks whether its the first round
		if (IsFirst == true) {
			// Sets table to 2 of clubs
			Table1.SetValue(Hand3.GetCard(SuitInUse, true, HeartsBroken), 3);
		}
		else {
			// If it isnt the first round then the card selected will become the suit for that round
			Card Choise = Hand3.GetCard(4, false, HeartsBroken);
			// Sets suit to chosen suit
			SuitInUse = Choise.ReturnSuit();
			// Sets position 3 on the table to the selected card
			Table1.SetValue(Choise, 3);
		}
		// Gets the choice of hand from the other players and set them on the table in the correct position
		Table1.SetValue(Hand4.GetCard(SuitInUse, false, true), 4);
		Table1.Output();
		Table1.SetValue(Hand1.GetCard(SuitInUse, false, true), 1);
		Table1.SetValue(Hand2.GetCard(SuitInUse, false, true), 2);
	}
	if (Order == 4) {
		// Checks whether its the first round
		if (IsFirst == true) {
			// Sets table to 2 of clubs
			Table1.SetValue(Hand4.GetCard(SuitInUse, true, HeartsBroken), 4);
		}
		else {
			// If it isnt the first round then the card selected will become the suit for that round
			Card Choise = Hand4.GetCard(4, false, HeartsBroken);
			// Sets suit to chosen suit
			SuitInUse = Choise.ReturnSuit();
			// Sets position 4 on the table to the selected card
			Table1.SetValue(Choise, 4);
		}
		Table1.Output();
		// Gets the choice of hand from the other players and set them on the table in the correct position
		Table1.SetValue(Hand1.GetCard(SuitInUse, false, true), 1);
		Table1.SetValue(Hand2.GetCard(SuitInUse, false, true), 2);
		Table1.SetValue(Hand3.GetCard(SuitInUse, false, true), 3);
	}
	// Outputs the table and resizes the hands
	Table1.Output();
	Hand1.ResizeHand();
	Hand2.ResizeHand();
	Hand3.ResizeHand();
	Hand4.ResizeHand();

	// Gets table score
	int Score = Table1.GetTableScore();
	// Gets the player who won
	int Player = Table1.GetHighestCard(SuitInUse);
	// If there is a score that isnt 0 or just the queen, it breaks the hearts
	if (Score != 0 && Score != 13) {
		HeartsBroken = true;
	}
	// Chooses the player who lost the hand
	switch (Player) {
	case 1:
		// Increments their score
		Player1Score += Score;
		// Increases the order
		Order = 1;
		break;
	case 2:
		// Increments their score
		Player2Score += Score;
		// Increases the order
		Order = 2;
		break;
	case 3:
		// Increments their score
		Player3Score += Score;
		// Increases the order
		Order = 3;
		break;
	case 4:
		// Increments their score
		Player4Score += Score;
		// Increases the order
		Order = 4;
		break;
	}
}

// Prints the scores
void GameManager::PrintScores()
{
	cout << endl;
	cout << "Player 1 Score: " << Player1Score << endl;
	cout << "Player 2 Score: " << Player2Score << endl;
	cout << "Player 3 Score: " << Player3Score << endl;
	cout << "Player 4 Score: " << Player4Score << endl;
	cout << endl;
}

// Gets the player score (used for saving)
int GameManager::GetScore(int Player)
{
	if (Player == 1) {
		return Player1Score;
	}
	else if (Player == 2) {
		return Player2Score;
	}
	else if (Player == 3) {
		return Player3Score;
	}
	else if (Player == 4) {
		return Player4Score;
	}
	else {
		return 0;
	}
}

// Sets the players scores (Used for loading)
void GameManager::SetScore(int Player, int Score)
{
	if (Player == 1) {
		Player1Score = Score;
	}
	else if (Player == 2) {
		Player2Score = Score;
	}
	else if (Player == 3) {
		Player3Score = Score;
	}
	else if (Player == 4) {
		Player4Score = Score;
	}
}

// Simple get method
int GameManager::GetDirection()
{
	return Direction;
}

// Simple set method
void GameManager::SetDirection(int DesiredDirection)
{
	Direction = DesiredDirection;
}
