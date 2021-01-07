#include "Container.h";
#include <iostream>;

Container::Container(int Size)
{
	// Creates a Card Vector used by all of the child classes with the inputted size
	vector<Card*> Storage(Size);
}

// Defines the void which can be overwritten by child classes declaring the function again
// Otherwise calling .Output() will use this function
void Container::Output()
{
	for (int i = 0; i < 52; i++) {
		// Prints the whole deck
		Storage[i].GetNum();
		Storage[i].GetSuit();
		cout << endl;
	}
}

// Returns a card at the index
Card Container::GetCard(int Index)
{
	return Storage[Index];
}
