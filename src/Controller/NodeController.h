/*
 * NodeController.h
 *
 *  Created on: Jan 27, 2016
 *      Author: thod0127
 */

#ifndef CONTROLLER_NODECONTROLLER_H_
#define CONTROLLER_NODECONTROLLER_H_
#include"../Model/Node.h";
#include "../Model/Node.cpp";
#include <string>;
using namespace std;

class NodeController
{
private:
	Node<string> stringNode;
	Node<int> intNode;
public:
	NodeController();
	virtual ~NodeController();
	void start();
};

#endif /* CONTROLLER_NODECONTROLLER_H_ */
