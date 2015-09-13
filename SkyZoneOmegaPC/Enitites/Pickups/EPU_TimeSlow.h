#pragma once

#include <SDL.h>
#include "EPU_Pickup.h"
#include "../../Core/C_Vec2.h"

/**
@brief Contains the data and functions for the TimeSlow power up.
@author Jamie Slowgrove
*/
class EPU_TimeSlow : public EPU_Pickup
{
public:
	/**
	@brief Constructs the TimeSlow power up object.
	@param sprite A pointer to the objects Texture.
	@param pos The position of the TimeSlow power up.
	@param dimensions The dimensions of the TimeSlowTimeSlow power up.
	@param screenDimensions The dimensions of the screen.
	@param velocities The velocities of the TimeSlow power up.
	@param universalSpeed A pointer for the universal speed of the game.
	*/
	EPU_TimeSlow(C_Texture* sprite, C_Vec2 pos, C_Vec2 dimensions, C_Vec2 screenDimensions, 
		C_Vec2 velocities, float* universalSpeed);

	/**
	@brief Destructs the TimeSlow power up object.
	*/
	~EPU_TimeSlow();
};