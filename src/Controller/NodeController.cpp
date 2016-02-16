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
	notHipsterDoubles = new CTECArray<double>(5);
}

NodeController::~NodeController()
{

}

void NodeController :: start()
{
	arrayTimer.startTimer();

	for(int index = 0; index < notHipsterInts->getSize(); index++)
	{
		notHipsterInts->set(index, (index + 1));
	}

	for(int index = notHipsterInts->getSize() - 1; index >= 0; index--)
	{
		cout << "The int in spot " << index << " are: " << notHipsterInts->get(index) << endl;
	}

	for(int index = 0; index < notHipsterDoubles->getSize(); index++)
	{
		notHipsterDoubles->set(index, (index + 0.5));
	}

	for(int index = notHipsterDoubles->getSize() - 1; index >= 0; index--)
	{
		cout << "The double in spot " << index << " are: " << notHipsterDoubles->get(index) << endl;
	}

	arrayTimer.stopTimer();
	arrayTimer.displayTimerInformation();
}
