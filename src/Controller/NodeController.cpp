/*
 * NodeController.cpp
 *
 *  Created on: Jan 27, 2016
 *      Author: thod0127
 */

#include "NodeController.h";
#include <iostream>;
using namespace std;

NodeController::NodeController()
{
	stringNode.setValue("wasdwasdwasd");
	intNode.setValue(10);

	stringArrayNode.setValue("Words in here :D");
	otherArrayNode.setValue("Linked node");
	stringArrayNode.setNext(&otherArrayNode);
}

NodeController::~NodeController()
{

}

void NodeController :: start()
{
	cout << "The contents of the stringNode are: " << stringNode.getValue() << endl;

	cout << "The contents of the stringArrayNode are: " << stringArrayNode.getValue() << endl;
	cout << "This is connected to stringArrayNode: " << (*stringArrayNode.getNext()).getValue() << endl;
}
