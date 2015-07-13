#include "C_Timer.h"

C_Timer::C_Timer(float timerLength) : timerLength(timerLength)
{
	resetTimer();
}

C_Timer::~C_Timer()
{	
}

void C_Timer::upadateTimer(float deltaTime)
{
	//Update the timer
	timer += deltaTime;
	//If the timer has finished then set the timer to finished
	if (timer >= timerLength)
	{
		finished = true;
	}
}

void C_Timer::resetTimer()
{
	//Set the current time to 0
	timer = 0.0f;
	//Set the timer to not be finished
	finished = false;
}

void C_Timer::setTimerLength(float timerLength)
{
	//set the timer length
	this->timerLength = timerLength;

	//reset the timer
	resetTimer();
}

bool C_Timer::checkTimer()
{
	return finished;
}