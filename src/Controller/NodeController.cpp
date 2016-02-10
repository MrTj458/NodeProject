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
	notHipsterInts = new CTECArray<int>(5);
}

NodeController::~NodeController()
{

}

void NodeController :: start()
{
	for(int index = 0; index < notHipsterInts->getSize(); index++)
	{
		notHipsterInts->set(index, (index + 1));
	}

	for(int index = notHipsterInts->getSize() - 1; index >= 0; index--)
	{
		cout << "The contents of spot " << index << " are: " << notHipsterInts->get(index) << endl;
	}
}
