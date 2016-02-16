/*
 * Timer.cpp
 *
 *  Created on: Feb 16, 2016
 *      Author: thod0127
 */

#include "Timer.h"

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

