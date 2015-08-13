#pragma once

#include <SDL.h>
#include "E_Pickup.h"
#include "../Core/C_Vec2.h"

/**
@brief Contains the data and functions for the FirePowerUp.
@author Jamie Slowgrove
*/
class E_FirePowerUp : public E_Pickup
{
public:
	/**
	@brief Constructs the FirePowerUp object.
	@param sprite A pointer to the objects Texture.
	@param pos The position of the FirePowerUp.
	@param dimensions The dimensions of the FirePowerUp.
	@param screenDimensions The dimensions of the screen.
	@param velocities The velocities of the FirePowerUp.
	*/
	E_FirePowerUp(C_Texture* sprite, C_Vec2 pos, C_Vec2 dimensions, C_Vec2 screenDimensions, C_Vec2 velocities);

	/**
	@brief Destructs the FirePowerUp object.
	*/
	~E_FirePowerUp();
};