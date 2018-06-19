#ifndef DOUBLELIST
#define DOUBLELIST
#include <iostream>
using namespace std; 

template <class Type>
class DoubleList
{
private:
	class Node
	{
	public:
		Type element;
		Node *previous;
		Node *next;

		Node() : next(nullptr) {}
		Node(Type newElement, Node *newPrevious = nullptr, Node *newNext = nullptr) :
			element(newElement), previous(newPrevious), next(newNext) {}
	};
	Node *left;
	Node *right;

public:
	// Constructors and destructor
	DoubleList();
	~DoubleList();

	// List functions
	bool empty() const;
	bool insert(const Type& newElement);
	bool remove(const Type& delElement);
	void displayLtoR(ostream& outStream) const;
	void displayRtoL(ostream& outStream) const;
};
#endif