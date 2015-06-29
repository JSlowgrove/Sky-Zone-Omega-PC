#pragma once

/**
@brief Handles timer functions.
@author Jamie Slowgrove
*/
class C_Timer
{
public:
	/**
	@brief Constructs the timer object.
	@param float the length of the timer.
	*/
	C_Timer(float timerLength);

	/**
	@brief Destructs the timer object.
	*/
	~C_Timer();

	/**
	@brief Updates the timer using the delta time.
	@param dt The delta time.
	*/
	void upadateTimer(float dt);

	/**
	@brief Resets the timer to 0.
	*/
	void resetTimer();

	/**
	@brief Returns if the timer has finished or not.
	@returns If the timer has finished.
	*/
	bool checkTimer();

private:
	///The current time in the timer.
	float timer;
	///The length of the timer.
	float timerLength;
	///A boolean for if the timer has finished
	bool finished;
};