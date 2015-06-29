#pragma once

#include <string>
#include <SDL.h>

///A definition of PI.
#define PI 3.141596f

/**
@brief Contains utility functions for use within the code.
@author Jamie Slowgrove
*/
namespace C_Utilities
{
	/**
	@brief Gets the value for PI.
	@returns The value for PI.
	*/
	float getPI();

	/**
	@brief Converts the degree to a radian.
	@param angle The angle to convert.
	@returns The converted radian.
	*/
	float convertDegreeToRadian(float angle);

	/**
	@brief Converts the radian to a degree.
	@param angle The angle to convert.
	@returns The converted degree.
	*/
	float convertRadianToDegree(float angle);

	/**
	@brief Logs the information message.
	@param message The message.
	*/
	void logI(std::string message);

	/**
	@brief Logs the error message.
	@param message The message.
	*/
	void logE(std::string message);
}