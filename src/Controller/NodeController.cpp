/*
 * NodeController.cpp
 *
 *  Created on: Jan 27, 2016
 *      Author: thod0127
 */

#include "NodeController.h"
#include <iostream>
using namespace std;

NodeController::NodeController()
{
	numbers = new CTECList<int>();
}

NodeController::~NodeController()
{

}

void NodeController :: start()
{
	testLists();
}

void NodeController::testLists()
{
	numbers->addAtIndex(0, 1);
	cout << numbers->getFront() << endl;
}
