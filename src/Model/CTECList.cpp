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
	return size;
}

template <class Type>
void CTECList<Type>::calculateSize()
{
	assert(size >= 0);

	int count = 0;
	if(head == nullptr)
	{
		size = count;
	}
	else
	{
		count++;
		ArrayNode<Type> * current = head;
		while(current->getNext != nullptr)
		{
			count++;
			current = current->getNext();
		}
		size = count;
	}
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
	ArrayNode<Type> * newNode = new ArrayNode<Type>(value);
	ArrayNode<Type> * end = head;
	while(end->getNext() != nullptr)
	{
		end = end->getNext();
	}

	end->setNext(newNode);
}

template <class Type>
void CTECList<Type>::addAtIndex(int index, const Type& value)
{
	ArrayNode<Type> * newNode = new ArrayNode<Type>(value);
	ArrayNode<Type> * current = head;
	for(int spot = 0; spot < index-1; spot++)
	{
		current = current->getNext();
	}
	newNode->setNext(current->getNext());
	current->setNext(newNode);
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
	assert(index >= 0 && index < size);

	ArrayNode<Type> * current = head;
	for(int spot = 0; spot < index; spot++)
	{
		current = current->getNext();
	}

	return current->getValue();
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
	thingToRemove = this->head->getValue();
//Remove head
	delete this->head;
//Move head to next spot
	this->head = newHead;
	this->calculateSize();

	return thingToRemove;
}

template <class Type>
Type CTECList<Type>::removeFromEnd()
{
	assert(this->size > 0);

	ArrayNode<Type> * end = head;
	while(!end->getNext() == nullptr)
	{
		end = end->getNext();
	}
	Type temp = end->getValue;

	ArrayNode<Type> * newEnd = head;
	for(int index = 0; index > size-1; index++)
	{
		newEnd = newEnd->getNext();
	}

	newEnd->setNext(nullptr);

	delete end;
	this->calculateSize();
	return temp;
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
	assert(index >= 0 && index < size);

	ArrayNode<Type> * current = head;
	for(int spot = 0; spot < index; spot++)
	{
		current = current->getNext();
	}

	current->setValue(value);
}
