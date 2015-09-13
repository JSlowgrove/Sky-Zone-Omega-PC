#pragma once

#include <SDL.h>
#include "EPU_Pickup.h"
#include "../../Core/C_Vec2.h"

/**
@brief Contains the data and functions for the Shield.
@author Jamie Slowgrove
*/
class EPU_Shield : public EPU_Pickup
{
public:
	/**
	@brief Constructs the Shield object.
	@param sprite A pointer to the objects Texture.
	@param pos The position of the Shield.
	@param dimensions The dimensions of the Shield.
	@param screenDimensions The dimensions of the screen.
	@param velocities The velocities of the Shield.
	@param universalSpeed A pointer for the universal speed of the game.
	*/
	EPU_Shield(C_Texture* sprite, C_Vec2 pos, C_Vec2 dimensions, C_Vec2 screenDimensions, 
		C_Vec2 velocities, float* universalSpeed);

	/**
	@brief Destructs the Shield object.
	*/
	~EPU_Shield();
};