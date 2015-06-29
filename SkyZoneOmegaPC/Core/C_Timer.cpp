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
	//If the timer is 1 then set the timer to finished
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

bool C_Timer::checkTimer()
{
	return finished;
}