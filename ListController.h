#include "DoubleListTemplate.h"

class ListController
{
private:
	DoubleList<int> doubleList;
public:
	ListController();
	void displayWelcome();
	void displayMenu();
	void displayAscending();
	void displayDescending();
	void add();
	void remove();
};