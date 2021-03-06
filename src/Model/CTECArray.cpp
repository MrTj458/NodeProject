/*
 * CTECArray.cpp
 *
 *  Created on: Feb 2, 2016
 *      Author: thod0127
 */

#include "CTECArray.h"
#include <iostream>
#include <assert.h>
using namespace std;

/*
 * Constructor for the CTECArray.
 * Takes a integer parameter for the size of the array.
 * Builds the Array and links the Nodes.
 */
template <class Type>
CTECArray<Type>::CTECArray(int size)
{
	this->size = size;
	this->head = nullptr;

	//Defensive code
	assert(size > 0);

	for(int index = 0; index < size; index++)
	{
		if(head != nullptr)
		{	//Regular ArrayNodes are being made.
			ArrayNode<Type> * nextNode = new ArrayNode<Type>();
			nextNode->setNext(head);
			this->head = nextNode;
		}
		else
		{	//The first ArrayNode needs to be made.
			ArrayNode<Type> * firstNode = new ArrayNode<Type>();
			this->head = firstNode;
		}
	}
}

/*
 * Destructor for the CTECArray.
 * Deletes all of the Node and ArrayNode objects from memory.
 */
template <class Type>
CTECArray<Type>::~CTECArray()
{
	ArrayNode<Type> * deleteMe = head;
	for(int index = 0; index < size; index++)
	{
		if(deleteMe->getNext() != nullptr)
		{
			head = deleteMe->getNext();
			deleteMe->setNext(nullptr);
		}

		delete deleteMe;
		deleteMe = head;
	}

	delete head;
}

/*
 * returns the size of the CTECArray object.
 */
template <class Type>
int CTECArray<Type>::getSize()
{
	return this->size;
}

/*
 * Returns the value of the Node in the inputed position.
 */
template <class Type>
Type CTECArray<Type>::get(int position)
{
	//check for out of bounds
	assert(position < size && position >= 0);
	//Inbounds
	ArrayNode<Type> * current = head;
	for(int spot = 0; spot <= position; spot++)
	{
		if(spot != position)
		{
			current = current->getNext();
		}
		else
		{
			return current->getValue();
		}
	}
}

/*
 * Sets the value of the inputed position to the inputed value.
 */
template <class Type>
void CTECArray<Type>::set(int position, const Type& value)
{
	//Check for out of bounds.
	assert(position < size && position >= 0);
	//Inbounds
	ArrayNode<Type> * current = head;
	for(int spot = 0; spot <= position; spot++)
	{
		if(spot != position)
		{
			current = current->getNext();
		}
		else
		{
			current->setValue(value);
		}
	}
}
