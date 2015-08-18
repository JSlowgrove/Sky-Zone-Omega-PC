#pragma once

#include <SDL.h>
#include "EPU_Pickup.h"
#include "../../Core/C_Vec2.h"

/**
@brief Contains the data and functions for the KillAll power up.
@author Jamie Slowgrove
*/
class EPU_KillAll : public EPU_Pickup
{
public:
	/**
	@brief Constructs the KillAll power up object.
	@param sprite A pointer to the objects Texture.
	@param pos The position of the KillAll power up.
	@param dimensions The dimensions of the KillAll power up.
	@param screenDimensions The dimensions of the screen.
	@param velocities The velocities of the KillAll power up.
	*/
	EPU_KillAll(C_Texture* sprite, C_Vec2 pos, C_Vec2 dimensions, C_Vec2 screenDimensions, C_Vec2 velocities);

	/**
	@brief Destructs the KillAll power up object.
	*/
	~EPU_KillAll();
};