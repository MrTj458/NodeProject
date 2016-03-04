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


}

NodeController::~NodeController()
{

}

void NodeController :: start()
{
 CTECList<int> myList;
 myList.addToEnd(0);
 myList.addToEnd(1);
 myList.addToEnd(2);
 myList.addToEnd(3);
 myList.addToEnd(4);
 myList.addToEnd(5);
 myList.removeFromEnd();
 cout << myList.getEnd() << endl;
}
