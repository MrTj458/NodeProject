/*
 * CTECArray.cpp
 *
 *  Created on: Feb 2, 2016
 *      Author: thod0127
 */

#include "CTECArray.h"
#include <iostream>
using namespace std;

template <class Type>
CTECArray<Type>::CTECArray(int size)
{
	this->size = size;
}

template <class Type>
CTECArray<Type>::~CTECArray()
{

}

template <class Type>
int CTECArray<Type>::getSize()
{
	return this->size;
}

template <class Type>
Type* CTECArray<Type>::get(int position)
{
	//We need to do bounds cheing so we do not crash the program.
	if(position >= size || position < 0)
	{
		//Out of bounds
		cerr << "position value is out of bounds :(" << endl;
		return nullptr;
	}
	else
	{
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
}

template <class Type>
void CTECArray<Type>::set(int position, Type value)
{

}
