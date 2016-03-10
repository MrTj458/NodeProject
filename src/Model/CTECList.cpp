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

/*
 * 1: Start at head
 * 2: Iterate over nodes
 * 3: Update position, then delete
 * 4: Delete final
 * 5: Reset size, head, end to default
 */
template <class Type>
CTECList<Type>::~CTECList()
{
	ArrayNode<Type> * current = head;

	while(current->getNext() != nullptr)
	{
		ArrayNode<Type> * temp = current;

		current = current->getNext();
		head = current;
		delete temp;
	}

	delete head;
	head = nullptr;
	end = nullptr;
	size = 0;
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
		while(current->getNext() != nullptr)
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
	this->calculateSize();

	if(size == 0)
	{
		end = head;
	}
}

template <class Type>
void CTECList<Type>::addToEnd(const Type& value)
{
	if(size == 0)
	{
		addToFront(value);
	}
	else
	{
		ArrayNode<Type> * newNode = new ArrayNode<Type>(value);
		ArrayNode<Type> * endNode = head;
		while(endNode->getNext() != nullptr)
		{
			endNode = endNode->getNext();
		}

		endNode->setNext(newNode);
	}
	this->calculateSize();
}

template <class Type>
void CTECList<Type>::addAtIndex(int index, const Type& value)
{
	assert(index <= size);
	assert(index >= 0);

	if(index == 0)
	{
		addToFront(value);
	}
	else if(index == size-1)
	{
		addToEnd(value);
	}
	else
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
	this->calculateSize();
}

template <class Type>
Type CTECList<Type>::getFront()
{
	return head->getValue();
}

template <class Type>
Type CTECList<Type>::getEnd()
{
	ArrayNode<Type> * endNode = head;
	while(endNode->getNext() != nullptr)
	{
		endNode = endNode->getNext();
	}

	return endNode->getValue();
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

	Type thingToRemove;

	ArrayNode<Type> * newHead = new ArrayNode<Type>();
	newHead = this->head->getNext();
	thingToRemove = this->head->getValue();

	delete this->head;

	this->head = newHead;
	this->calculateSize();

	return thingToRemove;
}

template <class Type>
Type CTECList<Type>::removeFromEnd()
{
	assert(this->size > 0);

	Type returnValue;

	if(size == 1)
	{
		returnValue = removeFromFront();
	}
	else
	{
		ArrayNode<Type> * previous = head;
		for(int index = 0; index < size - 2; index++)
		{
			previous = previous->getNext();
		}
		ArrayNode<Type> * deleteMe = previous->getNext();
		returnValue = deleteMe->getValue();
		delete deleteMe;
		previous->setNext(nullptr);
	}

	this->calculateSize();
	return returnValue;
}

template <class Type>
Type CTECList<Type>::removeFromIndex(int index)
{
	assert(this->size > 0);
	assert(index >= 0 && index < size);

	Type thingToRemove;

	ArrayNode<Type> * previous = head;
	ArrayNode<Type> * deleteMe = head;
	ArrayNode<Type> * newNext = head;


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
		for(int spot = 0; spot < index-1; spot++)
		{
			previous = previous->getNext();
		}

		deleteMe = previous->getNext();
		newNext = deleteMe->getNext();

		thingToRemove = deleteMe->getValue();

		previous->setNext(newNext);
		delete deleteMe;
	}
	this->calculateSize();
	return thingToRemove;
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
