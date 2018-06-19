#include "ListController.h"

int main()
{
	ListController currentSession;
	int menuChoice = 1;

	currentSession.displayWelcome();

	while (menuChoice != 0)
	{
		currentSession.displayMenu();
		cin >> menuChoice;


while (cin.fail() || menuChoice < 0 || menuChoice > 4 || cin.peek() == '.')
		{
			cout << endl << "That's not a valid choice, please enter 1-4, or 0 to exit: " << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cin >> menuChoice;
		}

		switch (menuChoice)
		{
		case 1:
			// Add a number to the list in order
			currentSession.add();
			break;

		case 2:
			// Delete the given number from the list
			currentSession.remove();
			break;

		case 3:
			// Display list in ascending order
			currentSession.displayAscending();
			break;

		case 4:
			// Display list in descending order
			currentSession.displayDescending();
			break;

		case 0:
			// If the user wants to exit, display tdon't display an error message and exit.
			break;

		default:
			// If not an expected entry, get a new choice number
			cout << "That's not a valid choice, please enter 1-4, or 0 to exit: " << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cin >> menuChoice;
			break;
		}
	}
	
	return 0;
}