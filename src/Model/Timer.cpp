/*
 * Timer.cpp
 *
 *  Created on: Feb 16, 2016
 *      Author: thod0127
 */

#include "Timer.h"
#include <iostream>
#include <iomanip>
using namespace std;

Timer::Timer()
{
	executionTime = 0;
}

Timer::~Timer()
{
	// TODO Auto-generated destructor stub
}

void Timer::displayTimerInformation()
{
	cout << fixed;
	cout << setprecision(8);

	cout << executionTime << " μs (microseconds) for the code " << endl;
	cout << "Which is " << float(executionTime)/CLOCKS_PER_SEC << " seconds." << endl;
}

void Timer::startTimer()
{
	executionTime = clock();
}

void Timer::stopTimer()
{
	executionTime = clock() - executionTime;
}

void Timer::resetTimer()
{
	executionTime = 0;
}

long Timer::getExecutionTimeInMicroseconds()
{
	return executionTime;
}

