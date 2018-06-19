#include "ListController.h"

ListController::ListController() : doubleList(DoubleList<int>())
{}


void ListController::displayWelcome()
{
	cout << "************************************************************************************" << endl;
	cout << "***                                    Welcome!                                  ***" << endl;
	cout << "***       This program will allow you to add and remove numbers to/from a        ***" << endl;
	cout << "***    sorted, doubly linked list, as well as display it in ascending and/or     ***" << endl;
	cout << "***                               descending order.                              ***" << endl;
	cout << "***                                                                              ***" << endl;
	cout << "************************************************************************************";
}

void ListController::displayMenu()
{
	cout << endl << endl << "1. Add a number to the list";
	cout << endl << "2. Delete a number from the list";
	cout << endl << "3. Display list in ascending order";
	cout << endl << "4. Display list in descending order";
	cout << endl << "Please enter the number of your choice: ";
}


void ListController::displayAscending()
{
	if (doubleList.empty())
		cout << endl << "The list is currently empty." << endl;
	else
		doubleList.displayLtoR(cout);
}


void ListController::displayDescending()
{
	if (doubleList.empty())
		cout << endl << "The list is currently empty." << endl;
	else
		doubleList.displayRtoL(cout);
}


void ListController::add()
{
	int numToAdd;

	cout << endl << endl << "Please enter the number you'd like to add to the list: ";
	cin >> numToAdd;
	
	while (cin.fail() || cin.peek() == '.')
	{
		cout << endl << "Sorry, that's not a valid number, please enter integer numbers only:";
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cin >> numToAdd;
	}
	
	if (doubleList.insert(numToAdd))
		cout << endl << "The number " << numToAdd << " was successfully added to the list.";
	else
		cout << endl << "There was a problem adding the number " << numToAdd << " to the list.";
}


void ListController::remove()
{
	int numToDel;

	doubleList.displayLtoR(cout);
	cout << endl << endl << "Please enter the number you'd like to remove from the list: ";
	cin >> numToDel;

	while (cin.fail() || cin.peek() == '.' || !doubleList.remove(numToDel))
	{
		if (cin.fail() || cin.peek() == '.')
			cout << endl << "Sorry, that's not a valid number, please enter integer numbers only:";
		else
			cout << endl << "Sorry, that number isn't in the list to delete, please select one from the list displayed above:";
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cin >> numToDel;
	}	
	cout << endl << "The number " << numToDel << " was successfully removed from the list.";	
}