/*
 * CTECList.cpp
 *
 *  Created on: Feb 22, 2016
 *      Author: thod0127
 */

#include "CTECList.h"

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

}

template <class Type>
Type CTECList<Type>::getEnd()
{

}

template <class Type>
Type CTECList<Type>::getFromIndex(int index)
{

}

template <class Type>
Type CTECList<Type>::removeFromFront()
{
//Find the next spot
	ArrayNode<Type> * newHead = new ArrayNode<Type>();
	newHead = head->getNext();
//Remove head
	delete head;
//Move head to next spot
	head = newHead;
}

template <class Type>
Type CTECList<Type>::removeFromEnd()
{

}

template <class Type>
Type CTECList<Type>::removeFromIndex(int index)
{

}

template <class Type>
Type CTECList<Type>::set(int index, const Type& value)
{

}
