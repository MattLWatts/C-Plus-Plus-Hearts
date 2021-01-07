#include <iostream>;
#include <cstdlib>;
#include "Card.h";
#include "Deck.h";
#include "Table.h";
#include "Hand.h";
#include "HandAi.h";
#include "HandPlayer.h";
#include "GameManager.h";
#include <ctime>;
#include <string>;
#include <fstream>;
#include <vector>;

using namespace std;

// Stores game data in text file
void DepositSaveData(GameManager &Game) {
	ofstream HighScores;
	// Opens the file
	HighScores.open("SaveGameData.txt");
	// Inserts information in the first 5 lines
	HighScores << Game.GetScore(1) << endl;
	HighScores << Game.GetScore(2) << endl;
	HighScores << Game.GetScore(3) << endl;
	HighScores << Game.GetScore(4) << endl;
	HighScores << Game.GetDirection() << endl;
	// Closes the file
	HighScores.close();
}

void ObtainSaveData(GameManager &Game) {
	ifstream HighScores;
	HighScores.open("SaveGameData.txt");
	string Score1, Score2, Score3, Score4, Direction;
	// Gets each line of the file
	getline(HighScores, Score1, '\n');
	getline(HighScores, Score2, '\n');
	getline(HighScores, Score3, '\n');
	getline(HighScores, Score4, '\n');
	getline(HighScores, Direction, '\n');
	// Sets information in the game script
	// Converting the strings of each line to intergers
	Game.SetScore(1, stoi(Score1));
	Game.SetScore(2, stoi(Score2));
	Game.SetScore(3, stoi(Score3));
	Game.SetScore(4, stoi(Score4));
	Game.SetDirection(stoi(Direction));
	// Closes the file
	HighScores.close();
}

int main() {
	// Creates an instance of the gamemanager to perform passes and plays of cards
	GameManager Game;
	char choice;
	bool CorrectInput = false;
	// Waits until correct input is set to true.
	do {
		cout << "Welcome to Hearts? " << endl;
		cout << "To play a new game enter (P) " << endl;
		cout << "To load save data enter (L) " << endl;
		cout << "To exit enter (E) " << endl;
		cin >> choice;
		// Checks that the char choice is any of the following
		if (choice == 'P' || choice == 'p' || choice == 'Play') {
			cout << endl;
			CorrectInput = true;
		}
		else if (choice == 'L' || choice == 'l' || choice == 'Load') {
			// Calls the obtain fucntion to get the game information
			ObtainSaveData(Game);
			cout << endl;
			CorrectInput = true;
		}
		else if (choice == 'E' || choice == 'e' || choice == 'Exit') {
			return 0;
		}
	} while (CorrectInput == false);
	// Used by the goto statement to restart the game
StartOfProgram:
	// Used so that randoms are seeded so they dont give the same result
	srand(time(NULL));
	// Amount of turns per game
	int Turns = 13;
	// Creates a new deck
	Deck NewDeck;
	// Fills the deck with the 52 in a normal deck
	NewDeck.FillDeck();
	// Shuffles the deck 50 times
	for (int i = 0; i < 50; i++) {
		NewDeck.Shuffle();
	}
	// Initialises a player hand with 13 cards
	HandPlayer Hand1(13);
	// Initialises 3 Ai decks each with 13 cards
	HandAi Hand2(13);
	HandAi Hand3(13);
	HandAi Hand4(13);
	// Creates a table
	Table NewTable;
	// Populates each hand with a part of the shuffled deck
	Hand1.PopulateHand(NewDeck,0,13);
	Hand2.PopulateHand(NewDeck, 13, 26);
	Hand3.PopulateHand(NewDeck, 26, 39);
	Hand4.PopulateHand(NewDeck, 39, 52);
	// Outputs the hand for the player to pick from
	Hand1.PrintHand();
	// Passes the cards between players
	Game.PassCards(Hand1,Hand2,Hand3,Hand4);
	// Outputs the players hand again now with 3 cards from another player
	Hand1.PrintHand();
	// Gets the players to play cards
	Game.PlayHand(Hand1, Hand2, Hand3, Hand4,NewTable,true);
	// Decreases turns by 1
	Turns -= 1;
	// Prints the scores
	Game.PrintScores();
	// Game loop
	// Keeps continuing until turns is 0
	while (Turns >= 1) {
		// Prints the players hand
		Hand1.PrintHand();
		// Plays the hand
		Game.PlayHand(Hand1, Hand2, Hand3, Hand4, NewTable, false);
		// Prints the scores
		Game.PrintScores();
		// Decreases turns by 1
		Turns -= 1;
	}
	// Sets correct input to false for the menu
	CorrectInput = false;
	do {
		// Displays text
		cout << "Do you want to continue playing? " << endl;
		cout << "To play next round enter (Y) " << endl;
		cout << "To quit enter (N) " << endl;
		cout << "To save enter (S) " << endl;
		// Gets input
		cin >> choice;
		// checks input
		if (choice == 'Y' || choice == 'y' || choice == 'Yes') {
			cout << endl;
			// goes to the the start of the main loop
			goto StartOfProgram;
		}
		else if(choice == 'N' || choice == 'n' || choice == 'No'){
			return 0;
		}
		else if (choice == 'S' || choice == 's' || choice == 'Save') {
			DepositSaveData(Game);
		}
	} while (CorrectInput == false);
}