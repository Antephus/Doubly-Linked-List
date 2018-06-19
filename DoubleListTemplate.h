#ifndef DOUBLELISTTEMPLATE_H
#define DOUBLELISTTEMPLATE_H
#include "DoubleList.h"


// Constructor
template <class Type>
DoubleList<Type>::DoubleList() : left(nullptr),
right(nullptr)
{}

// Destructor
template <class Type>
DoubleList<Type>::~DoubleList()
{
	Node *temp;

	while (left != nullptr)
	{
		temp = left;
		left = left->next;
		delete temp;
	}
}


// List management functions
template <class Type>
bool DoubleList<Type>::empty() const
{
	return (left == nullptr && right == nullptr) ? true : false;
}


template <class Type>
bool DoubleList<Type>::remove(const Type& delElement)
{
	Node *temp;

	if (empty())
		return false;
	// If it's at the beginning just delete it
	else if (left->element == delElement)
	{
		if (left == right)
			right = nullptr;

		temp = left;
		left = left->next;
		delete temp;
		return true;
	}
	// If it wasn't the first element and it was the only one, return false
	else if (left->next == nullptr)
		return false;
	// Otherwise
	else
	{
		temp = left->next;

		// Search for it
		while ((delElement > temp->element) && (temp->next != nullptr))
		{
			temp = temp->next;
		}

		// If it's found, delete it
		if (delElement == temp->element)
		{
			// If it was the last one in the list, move the right pointer, otherwise, move the previous pointer for the next node
			if (right == temp)
				right = temp->previous;
			else
				(temp->next)->previous = temp->previous;

			(temp->previous)->next = temp->next;	
			
			delete temp;
			return true;
		}
		else  // The item to be deleted wasn't in the list
			return false;
	}
}


// Insert in order
template <class Type>
bool DoubleList<Type>::insert(const Type& newElement)
{
	Node *marker;
	Node *newNode = new Node(newElement, nullptr, nullptr);

	if (empty())
	{
		left = newNode;
		right = newNode;
		return true;
	}
	// If it's the lowest number, insert it at the start
	else if (left->element >= newElement)
	{
		newNode->next = left;
		left->previous = newNode;
		left = newNode;
		return true;
	}
	// If it's the highest number, insert it at the end
	else if (right->element <= newElement)
	{
		newNode->previous = right;
		right->next = newNode;
		right = newNode;
		return true;
	}
	else
	{
		// Find the first node that is higher than or equal to the value to be added 
		marker = left;

		do
		{
			marker = marker->next;
		} while ((newElement > marker->element));

		// Insert the new node before this node in the list
		newNode->next = marker;
		newNode->previous = marker->previous;
		(marker->previous)->next = newNode;
		marker->previous = newNode;
		return true;
	}
}


// Display functions
template <class Type>
void DoubleList<Type>::displayLtoR(ostream& outStream) const
{
	Node *marker = left;

	cout << endl << endl << "List Contents: ";
	while (marker != nullptr)
	{
		outStream << marker->element << " ";
		marker = marker->next;
	}
}


template <class Type>
void DoubleList<Type>::displayRtoL(ostream& outStream) const
{
	Node *marker;
	marker = right;

	cout << endl << endl << "List Contents: ";
	while (marker != nullptr)
	{
		outStream << marker->element << " ";
		marker = marker->previous;
	}
}
#endif
