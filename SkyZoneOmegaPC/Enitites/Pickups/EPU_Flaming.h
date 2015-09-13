#pragma once

#include <SDL.h>
#include "EPU_Pickup.h"
#include "../../Core/C_Vec2.h"

/**
@brief Contains the data and functions for the Flaming power up.
@author Jamie Slowgrove
*/
class EPU_Flaming : public EPU_Pickup
{
public:
	/**
	@brief Constructs the Flaming power up object.
	@param sprite A pointer to the objects Texture.
	@param pos The position of the Flaming power up.
	@param dimensions The dimensions of the Flaming power up.
	@param screenDimensions The dimensions of the screen.
	@param velocities The velocities of the Flaming power up.
	@param universalSpeed A pointer for the universal speed of the game.
	*/
	EPU_Flaming(C_Texture* sprite, C_Vec2 pos, C_Vec2 dimensions, C_Vec2 screenDimensions, 
		C_Vec2 velocities, float* universalSpeed);

	/**
	@brief Destructs the Flaming power up object.
	*/
	~EPU_Flaming();
};