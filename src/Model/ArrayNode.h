/*
 * ArrayNode.h
 *
 *  Created on: Jan 29, 2016
 *      Author: thod0127
 */

#ifndef MODEL_ARRAYNODE_H_
#define MODEL_ARRAYNODE_H_

#include "Node.h"

template <class Type>
class ArrayNode : public Node<Type>
{
private:
	ArrayNode * next;
public:
	ArrayNode();
	ArrayNode(Type value);
	ArrayNode(Type value, ArrayNode * next);
	virtual ~ArrayNode();
};

#endif /* MODEL_ARRAYNODE_H_ */
