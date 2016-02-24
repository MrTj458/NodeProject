/*
 * CTECList.cpp
 *
 *  Created on: Feb 22, 2016
 *      Author: thod0127
 */

#include "CTECList.h"
#include <iostream>
#include <assert.h>
using namespace std;

template <class Type>
CTECList<Type>::CTECList()
{
	this->size = 0;
	this->head = nullptr;
	this->end = nullptr;
}

template <class Type>
CTECList<Type>::~CTECList()
{
	// TODO Auto-generated destructor stub
}

template <class Type>
int CTECList<Type>::getSize()
{

}

template <class Type>
void CTECList<Type>::addToFront(const Type& value)
{
	ArrayNode<Type> * newNode = new ArrayNode<Type>(value, head);
	this->head = newNode;
}

template <class Type>
void CTECList<Type>::addToEnd(const Type& value)
{

}

template <class Type>
void CTECList<Type>::addAtIndex(int index, const Type& value)
{

}

template <class Type>
Type CTECList<Type>::getFront()
{
	return this->head;
}

template <class Type>
Type CTECList<Type>::getEnd()
{
	return this->end;
}

template <class Type>
Type CTECList<Type>::getFromIndex(int index)
{

}

template <class Type>
Type CTECList<Type>::removeFromFront()
{
	assert(this->size > 0);
//Declare a variable of the type to return.
	Type thingToRemove;
//Find the next spot
	ArrayNode<Type> * newHead = new ArrayNode<Type>();
	newHead = this->head->getNext();
//Get what head is holding
	thingToRemove = this->head->getValue;
//Remove head
	delete this->head;
//Move head to next spot
	this->head = newHead;

	return thingToRemove;
}

template <class Type>
Type CTECList<Type>::removeFromEnd()
{

}

template <class Type>
Type CTECList<Type>::removeFromIndex(int index)
{
	assert(this->size > 0);
	assert(index >= 0 && index < size);

	Type thingToRemove;

	ArrayNode<Type> * previous, deleteMe, newNext;

	if(index == 0)
	{
		thingToRemove = removeFromFront();
	}
	else if(index == size-1)
	{
		thingToRemove = removeFromEnd();
	}
	else
	{
		for(int spot = 0; spot < index+1; spot++)
		{

		}
	}
}

template <class Type>
Type CTECList<Type>::set(int index, const Type& value)
{

}
